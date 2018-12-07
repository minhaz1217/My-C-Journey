#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int n,k,a,red,green,blue;
    cin >> n >> k;
    a=  0;
    red= ceil((double)n*2.00 / (double)k);
    green =  ceil((double)n*5 / (double)k);
    blue = ceil((double)n*8 / (double)k);
    //msg2(red, green, blue)
    cout << red + green + blue;
    return 0;
}
