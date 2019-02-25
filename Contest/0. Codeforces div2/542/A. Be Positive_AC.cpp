/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 24 / February / 2019
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
    double pos,neg,n,a,nd;
    neg = 0;
    pos = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a<0){
            neg++;
        }else if(a>0){
            pos++;
        }
    }
    nd = ceil(n/2.0);
    if(pos >= nd){
        cout << 1 << endl;
    }else if(neg>=nd){
        cout << -1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
