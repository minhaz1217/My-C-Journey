#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int myInt = 654;
    string binary = bitset<16>(myInt).to_string(); //to binary
    cout<<binary<<"\n";

    unsigned long decimal = bitset<16>(binary).to_ulong();
    cout<<decimal<<"\n";
    return 0;
}

