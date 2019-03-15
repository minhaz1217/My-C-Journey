/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10812
Date : 15 / March / 2019
Comment: got WA for some solutions. had to rethink the absolute difference part
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
    long long int tc;
    cin >> tc;
    while(tc--){
        long long int u,v,a1,b1,a2,b2;
        cin >> u >> v;
        a1 = (u+v)/2;
        b2 = (u+v)/2;
        b1 = u -a1;
        a2 = u -b2;
        if(a1 < 0 || b1<0 || a2<0 || b2<0){
            cout << "impossible" << endl;
        }else{
            if(a1 + b1 == u && abs(a1-b1) == v){
                cout << a1 << " "<< b1<<endl;
            }else if(a2 + b2 == u && abs(a2-b2) == v ){
                cout << a2 << " " << b2 << endl;
            }else{
                cout << "impossible" << endl;
            }
        }

    }


    return 0;
}
