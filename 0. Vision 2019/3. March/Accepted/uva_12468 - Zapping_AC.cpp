/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-12468
Date : 15 / March / 2019
Comment: easy cycle problem.
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
    int a,b,a1,a2,a3;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        a1 = abs(a-b);
        a2 = (100 -a)+b;
        a3 = a + (100-b);
        cout << min(a1, min(a2, a3)) << endl;
    }
    return 0;
}
