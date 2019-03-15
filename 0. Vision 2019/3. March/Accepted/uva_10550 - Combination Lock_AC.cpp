/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10550
Date : 15 / March / 2019
Comment: easy problem but there is a trick to notice.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define ccc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cc(int a, int b){
    if(a<=b){
        return b-a;
    }else{
        return (40-a)+b;
    }
}
int cw(int a, int b){
    if(a>=b){
        return a-b;
    }else{
        return a + (40-b);
    }
}
int main(){
    int a, b, c, d, sum;
    while(1){
        cin >> a >> b >> c >> d;
        if(!a && !b && !c && !d){
            break;
        }
        sum = 360*3;
        sum += (cw(a,b) + cc(b,c) + cw(c,d))*9;
        cout << sum << endl;
    }
    return 0;
}
