/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/302538#problem/C
Date : 22 / May / 2019
Comment: bad solution, only passed because it is a low level problem
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
    long long int n,a,b,sum,mn;
    cin >> n;
    while(n--){
        cin >> a;
        sum = 0;
        vector<long long int>vec;
        for(int i=0;i<a;i++){
            cin >> b;
            vec.push_back(b);
        }
        mn = INT_MAX;
        for(int i=1;i<=30000;i++){
                sum = 0;
            for(int j=0;j<vec.size();j++){
                sum += abs(i-vec[j]);
            }
            mn = min(sum, mn);
        }
        cout << mn << endl;
    }
    return 0;
}
