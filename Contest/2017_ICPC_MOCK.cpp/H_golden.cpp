#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double golden = 1.6180339887498948482045868343656;
    double rt = 2.2360679774997896964091736687313;
    double n = 1000;
    double d = (pow(golden, n)/rt) + .5;
    cout << floor(d) << endl;
    return 0;
}
