/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/302538#problem/B
Date : 22 / May / 2019
Comment: did an O(n2) solution, i don't personally like this solution
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

#define ll long long int

int main(){
    long long int u,v,x,mx = INT_MIN, mn = INT_MAX, prev;
    vector<long long int> vec;
    vec.assign(11000,0);
    while(cin >> u >> x >> v){
        for(int i=u;i<v;i++){
            vec[i] = max(vec[i], x);
        }
        mn = min(mn, min(u,v));
        mx = max(mx, max(u,v));
    }
    prev = -1;
    for(int i=mn;i<=mx+1;i++){
        if(vec[i] != prev){

            if(i>mn){
                cout << " ";
            }
                cout << i << " " << vec[i];

            prev = vec[i];
        }
    }
    cout << endl;
    return 0;
}
