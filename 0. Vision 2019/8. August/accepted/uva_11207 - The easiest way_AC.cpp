/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11207
Date : 11 / August / 2019
Comment: easy problem. once you get that you can either build a square or a rectangle.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    double n,currMax,mx,mn,a,b,pos;
    while(1){
        cin >> n;
        if(n ==0){
            break;
        }
        currMax = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            mx = min( min(a,b), max(a,b)/4);
            mn = min(a,b)/2.0;
            mn = max(mx,mn);
            if(mn > currMax){
                currMax = mn;
                pos = i+1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}
