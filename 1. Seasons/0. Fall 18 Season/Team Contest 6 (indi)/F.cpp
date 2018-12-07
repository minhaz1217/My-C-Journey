#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    vector<int>v;
    double i,n;
    n=0;
    i = 1;
    while(n<= 1e9){
        n = i * (i+1) /2;
        v.push_back(n);
        i++;
    }
    cc(v.size());
    cc(i)
    return 0;
}
