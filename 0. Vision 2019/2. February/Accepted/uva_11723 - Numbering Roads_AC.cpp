/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11723
Date : 28 / February / 2019
Comment: Very easy problem
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
    double r,n,d,caseCounter = 1;
    while(1){
        cin >> r >> n;
        if(r == 0 && n == 0){
            break;
        }
        cout << "Case " << caseCounter++<< ": ";
        if(r > (n)*26+n){
            cout << "impossible" << endl;
        }else{
            d = ceil((double)r/n);
            cout << d -1 << endl;
        }

    }

    return 0;
}
