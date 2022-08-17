/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/wear-mask
Complexity:
Date : 16 / Aug / 2022

Comment:
*/
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
    _INIT;

    unsigned long long int tc,a,b;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        a = a % 3 == 0 ? a/3 : a/3+1;
        b = b % 3 == 0 ? b/3 : b/3+1;
        cout << (unsigned long long int)(a*b) << endl;
        // cout << (long long int)(ceil((double)a/3.0) * ceil((double)b/3.0)) << endl;
    }
    return 0;
}
