#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector
using namespace std;
bool myfunction (int i,int j)
{
    //cout << i << " : " << j << endl;
    return (i>j);
}

int main ()
{
    int myints[] = {1,2,3,4,5,4,3,2,1};
    std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

    // using default comparison:
    std::sort (v.begin(), v.end());
    cout << "Looking for 20 " << binary_search (v.begin(), v.end(), 20) << endl;
    std::cout << "looking for a 3... ";

    if (std::binary_search (v.begin(), v.end(), 3)){
        cout << binary_search(v.begin(), v.end(), 3) << endl;
        std::cout << "found!\n";
    }
    else{
        std::cout << "not found. Returned: " << binary_search (v.begin(), v.end(), 3) << endl;;
    }


    // using myfunction as comp:
    std::sort (v.begin(), v.end(), myfunction);

    std::cout << "looking for a 6... ";
    if (std::binary_search (v.begin(), v.end(), 6, myfunction))
        std::cout << "found!\n";
    else{
        std::cout << "not found.\n";

    }
    return 0;
}
