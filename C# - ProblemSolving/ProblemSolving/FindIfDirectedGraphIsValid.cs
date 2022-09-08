using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemSolving
{
    public class FindIfDirectedGraphIsValid
    {

        public static void Run()
        {
            Console.WriteLine($"Is a valid path: {IsVisitedArrayValid(SampleDataSet(), GetAValidPath())}");
        }

        public static bool IsVisitedArrayValid(IList<Node> adjacencyList, IList<string> visited)
        {
            var alreadyVisited = new Dictionary<string, bool>();
            var graph = new Dictionary<string, IList<Node>>();

            // we are converting our visited array so that we can look up whether or not a node has been visited in minimal time.
            foreach (var node in visited)
            {
                alreadyVisited[node] = true;
            }

            foreach (var node in adjacencyList.Select(x => x.Id).Distinct())
            {
                graph[node] = new List<Node>();
            }

            // we are creating adjacency list from parents for our directed graph.
            foreach (var node in adjacencyList)
            {
                if (node.ParentId != null)
                {
                    graph[node.ParentId].Add(node);
                }
            }

            // BFS
            var queue = new Queue<string>();
            queue.Append("start");


            if(queue.Count > 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        public static IList<Node> SampleDataSet()
        {
            var sampleDataSet = new List<Node>();
            sampleDataSet.Add(new Node("start"));
            sampleDataSet.Add(new Node("A", "start"));
            sampleDataSet.Add(new Node("B", "A", "C1", "y"));
            sampleDataSet.Add(new Node("C", "A", "C1", "n"));
            sampleDataSet.Add(new Node("D", "A"));
            return sampleDataSet;
        }

        public static IList<string> GetAValidPath()
        {
            var validPaths = new List<List<string>>();
            validPaths.Add(new List<string> { "A", "D", "B", "E" });
            validPaths.Add(new List<string> { "A", "D", "C" });
            validPaths.Add(new List<string> { "A", "B", "D", "E" });
            validPaths.Add(new List<string> { "A", "B", "E", "D" });
            validPaths.Add(new List<string> { "A", "C", "D" });
            return validPaths[new Random().Next(0, validPaths.Count - 1)];

        }
        public class Node
        {
            public string Id { get; set; }                   // Node id & start, start will always be present.
            public string? ParentId { get; set; } = null;    // Parent of this node null if start node, otherwise
            public string? BranchId { get; set; }            // This is the BranchId based on this BranchChoice should be exclusive for paths
            public string? BranchChoice { get; set; }        // The BranchChoice for this BranchId
            public Node(string id, string? parentId = null, string? branchId = null, string? branchChoice = null)
            {
                Id = id;
                ParentId = parentId;
                BranchId = branchId;
                BranchChoice = branchChoice;
            }
        }
        /*
            Problem : From given a visited nodes array, check whether or not the visited arary is the valid state of a path that has ended correctly.
            
            The example input. 
          
                             -- (y) --> B --> E -> end
                        /C1\ 
                        \  / -- (n) --> C --> end
                       /
            start --> A
                       \--> D -> end
        
        The different valid paths are like this.
        A -> D -> B -> E
        A -> D -> C
        A -> B -> D -> E
        A -> B -> E -> D
        A -> C -> D
        
        From here our adjacencyList would look like this.
            start -> Id = start, ParentId = null, BranchId = null, BranchChoice = null;
                A -> Id = A, ParentId = Start, BranchId = null, BranchChoice = null;
                B -> Id = B, ParentId = A, BranchId = C1, BranchChoice = y;
                E -> Id = E, ParentId = B, BranchId = C1, BranchChoice = y;
                C -> Id = C, ParentId = A, BranchId = C1, BranchChoice = n;
                D -> Id = D, ParentId = A, BranchId = null, BranchChoice = null;
        
         */




    }
}
