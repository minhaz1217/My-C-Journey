#include <cmath>
#include <cstdlib>

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
/// Forward declarations.
template<size_t N> class ID3;
template<size_t N> class ID3Train;

/// Number of attributes in each sample.
constexpr size_t N = 4;
/// Floating point error.
constexpr float EPS = 1e-7;

/**
 * A single sample with attributes & target class.
 */
template<size_t N>
struct Sample {
  Sample()
  {
  }

  Sample(Sample &&sample)
    : attributes(std::move(sample.attributes))
    , clazz(std::move(sample.clazz))
  {
  }

  void operator = (Sample &&sample) {
    attributes = std::move(sample.attributes);
    clazz = std::move(sample.clazz);
  }

  // Array of attributes of the sample.
  std::array<std::string, N> attributes;
  // Class to which the sample belongs.
  std::string clazz;
};

/**
 * ID3 tree.
 */
template<size_t N>
class ID3 {
 public:
  std::string classify(const std::array<std::string, N> &sample)
  {
    return root_->classify(sample);
  }

  void print(std::ostream &os)
  {
    root_->print(os, 0);
  }

 private:
  class Node {
   public:
    virtual ~Node() {};
    virtual std::string classify(const std::array<std::string, N> &sample) = 0;
    virtual void print(std::ostream &os, size_t level) = 0;
  };

  class TerminalNode : public Node {
   public:
    TerminalNode(const std::string& clazz)
      : clazz_(clazz)
    {
    }

    std::string classify(const std::array<std::string, N> &sample) override {
      return clazz_;
    }

    void print(std::ostream &os, size_t level) override {
      for (size_t i = 0; i < level; ++i) {
        os << ' ';
      }
      os << clazz_ << std::endl;
    }

   private:
    std::string clazz_;
  };

  /// Inner node that makes a decision.
  class InnerNode : public Node {
   public:
    InnerNode(
        size_t attribute,
        std::string &&clazz,
        std::unordered_map<std::string, std::unique_ptr<Node>>&& branches)
      : attribute_(attribute)
      , clazz_(clazz)
      , branches_(std::move(branches))
    {
    }

    std::string classify(const std::array<std::string, N> &sample) override {
      auto it = branches_.find(sample[attribute_]);
      if (it == branches_.end()) {
        return clazz_;
      } else {
        return it->second->classify(sample);
      }
    }

    void print(std::ostream &os, size_t level) override {
      auto tabs = [&os, level] {
        for (size_t i = 0; i < level; ++i) {
          os << ' ';
        }
      };
      for (const auto &branch : branches_) {
        tabs(); os << branch.first << ":" << std::endl;
        branch.second->print(os, level + 1);
      }
    }

   private:
    size_t attribute_;
    std::string clazz_;
    std::unordered_map<std::string, std::unique_ptr<Node>> branches_;
  };

  ID3(std::unique_ptr<Node> &&root)
    : root_(std::move(root))
  {
  }

  /// Root node of the decision tree.
  std::unique_ptr<Node> root_;

  /// Only the trainer can construct this class.
  template<size_t M>  friend class ID3Train;
};

/**
 * ID3 Trainer.
 */
template<size_t N>
class ID3Train {
 private:
  // Some shorthand aliases.
  using ID3          = typename ::ID3<N>;
  using Node         = typename ::ID3<N>::Node;
  using TerminalNode = typename ::ID3<N>::TerminalNode;
  using InnerNode    = typename ::ID3<N>::InnerNode;
  using Sample       = typename ::Sample<N>;
  using Iter         = typename std::vector<typename ::Sample<N>>::iterator;

 public:
  ID3Train(std::vector<Sample> &&samples)
    : samples_(std::move(samples))
  {
  }

  std::unique_ptr<ID3> train()
  {
    return std::unique_ptr<ID3>(new ID3(train(samples_.begin(), samples_.end())));
  }

 private:
  std::unique_ptr<Node> train(Iter start, Iter end)
  {
    auto ig = std::make_pair(0, std::numeric_limits<float>::min());
    std::unordered_map<std::string, size_t> clazzes;
    std::string maxClazz;

    // For each attribute/value pair, compute how many items fall into that category.
    std::array<std::unordered_map<std::string, std::unordered_map<std::string, size_t>>, N> count;
    for (auto it = start; it != end; ++it) {
      for (size_t i = 0; i < N; ++i) {
        count[i][it->attributes[i]][it->clazz]++;
      }
      clazzes[it->clazz]++;
    }

    // Compute the entropy of the current set.
    auto entropy = 0.0f;
    auto total = end - start;
    for (auto clazz : clazzes) {
      auto p = clazz.second / (float)total;
      entropy -= p * log(p) / log(2.0f);

      if (!maxClazz.empty() && clazz.second > clazzes[maxClazz]) {
        maxClazz = clazz.first;
      }
    }

    // If set is all classified, return leaf node.
    if (abs(entropy) <= EPS) {
      return std::make_unique<TerminalNode>(start->clazz);
    }

    // Compute the information gain on all possible splits.
    for (size_t i = 0; i < N; ++i) {
      auto attribIG = entropy;
      for (auto split : count[i]) {
        auto setTotal = 0;
        for (auto clazz : split.second) {
          setTotal += clazz.second;
        }

        auto setEntropy = 0.0f;
        for (auto clazz : split.second) {
          auto p = clazz.second / (float)setTotal;
          setEntropy -= p * log(p) / log(2.0f);
        }
        attribIG -= (float)setTotal / (float)total * setEntropy;
      }
      if (attribIG >= ig.second) {
        ig.first = i;
        ig.second = attribIG;
      }
    }

    // Sort the set by the attribute index ig.first.
    auto attribIndex = ig.first;
    std::sort(start, end, [attribIndex] (const Sample &a, const Sample &b) {
      return a.attributes[attribIndex] < b.attributes[attribIndex];
    });

    // Split the samples by the attributes.
    auto setStart = start;
    std::unordered_map<std::string, std::unique_ptr<Node>> nodes;
    for (auto it = start + 1; it != end + 1; ++it) {
      if (it < end && it->attributes[attribIndex] == setStart->attributes[attribIndex]) {
        continue;
      }
      nodes[setStart->attributes[attribIndex]] = train(setStart, it);
      setStart = it;
    }

    return std::make_unique<InnerNode>(attribIndex, std::move(maxClazz), std::move(nodes));
  }

  std::vector<Sample> samples_;
};

/**
 * Entry point of the application.
 */
int main(int argc, char **argv)
{
  std::vector<Sample<N>> samples;

  // Read the samples.
  {
    std::ifstream is(argc >= 2 ? argv[1] : "data");
    while (!is.eof()) {
      Sample<N> sample;
      for (auto i = 0; i < N; ++i) {
        if (!(is >> sample.attributes[i])) {
          break;
        }
      }
      if (!(is >> sample.clazz)) {
        break;
      }
      samples.push_back(std::move(sample));
    }
  }

  // Train the ID3.
  auto id3 = ID3Train<N>(std::move(samples)).train();

  // Print the ID3 tree.
  id3->print(std::cout);

  // Classify some samples from stdin.
  {
    std::string line;
    while (line.resize(512), cin.getline(&line[0], line.size())) {
      line.resize(line.find_first_of('\0'));
      if (line.size() == 0) {
        break;
      }
      std::stringstream is(line);
      std::array<std::string, N> sample;
      for (auto i = 0; i < N; ++i) {
        if (!(is >> sample[i])) {
          return EXIT_SUCCESS;
        }
      }
      std::cout << id3->classify(sample) << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
