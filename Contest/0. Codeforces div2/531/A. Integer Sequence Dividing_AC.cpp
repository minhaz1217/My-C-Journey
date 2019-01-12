#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endint l;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    double n,sum;
    cin >>n;
    n = ceil(n/2);
    if((int)n%2 == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}
