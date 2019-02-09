/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/282946#problem/A
Date : 07 / February / 2019
Comment: pass:123456789, normal bigmod.
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

long long int bigmod(long long int b, long long int p, long long int m){
    // calculates (b^p)%m
    if(p==0){
        return 1%m;
    }
    int x = bigmod(b,p/2,m);
    x = (x*x)%m;
    if(p%2 == 1){
        x = (x*b) %m;
    }
    return x;
}

int main(){
    long long int b,p,m;
    while(cin >> b >> p >> m){
        cout << bigmod(b,p,m) << endl;
    }

    return 0;
}
