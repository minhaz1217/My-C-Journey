/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1114/problem/A
Date : 07 / February / 2019
Comment: Very very very easy problem, got WA 3 times, for no reason -_-'
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
    int x,y,z,a,b,c,flag = 1,currApple;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    currApple = a;
    if(currApple<x){
        flag = 0;
    }
    currApple = currApple - x;
    currApple = currApple + b;
    //msg("CURR", currApple)
    if(currApple< y){
        flag = 0;
    }
    currApple  = currApple -y;
    currApple = currApple + c;
    //msg("CURR", currApple)
    if(currApple < z){
        flag = 0;
    }
    currApple -= z;
    //msg2(a,b,currApple)
    if(currApple<0 || flag == 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}
