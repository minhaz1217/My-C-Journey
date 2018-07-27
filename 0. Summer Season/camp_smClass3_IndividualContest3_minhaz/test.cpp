#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 8

int main(){
    int a = 86;
    int b = 90;
    bitset<MX>b1(a);
    bitset<MX>b2(b);
    msg(a, b1)
    msg(b, b2)
    msg( (b-1|(b|a) ), ((b-1)&(b&a)))
    return 0;
}
