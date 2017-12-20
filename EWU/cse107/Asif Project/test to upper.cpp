#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <cctype>
using namespace std;
int main()
{
    string s;
    cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
    cout << s;
    return 0;

}
