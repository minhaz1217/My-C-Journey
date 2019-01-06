#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,a,b;
    cin >> n;
    a = floor(sqrt(n));

    b = n-(a*a);
    if(a*a == n){
        cout << a*2 << endl;
    }else if(b > a){
        cout << a*2 + 2 << endl;
    }else{
        cout << a*2 +1<< endl;
    }
    return 0;
}
