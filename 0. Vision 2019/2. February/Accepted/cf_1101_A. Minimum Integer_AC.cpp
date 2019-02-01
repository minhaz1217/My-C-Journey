//https://codeforces.com/contest/1101/problem/A
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    long long int tc,l,r,x;
    cin >> tc;
    while(tc--){
        cin >> l >> r >> x;
        if(x<l || x>r){
            cout << x << endl;
        }else {
            cout << ((int)(r/x)+1)*x << endl;
        }
    }

    return 0;
}
