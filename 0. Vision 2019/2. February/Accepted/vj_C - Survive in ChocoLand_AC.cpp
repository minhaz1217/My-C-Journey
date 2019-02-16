/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/283774#problem/C
https://www.codechef.com/problems/SURVIVE
Date : 16 / February / 2019
Comment: Very easy problem, tricky but fun and easy
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

int main()
{
    int tc;
    double n,k,s;
    cin >> tc;
    while(tc--){
        cin >> n >> k >> s;
        if(7*k > 6*n && s>=7){
            cout << -1 << endl;
        }else{
            cout << (int)ceil((k*s) /n) <<endl;
        }
    }
    return 0;
}
