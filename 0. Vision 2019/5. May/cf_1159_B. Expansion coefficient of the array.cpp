/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 12 / May / 2019
Comment:
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
    long long int n,a,mn,currRes;
    vector<long long int> vec;
    cin >> n;
    mn = LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    currRes = min(vec[0], vec[n-1])/(n-1);
    mn = vec[0];
    if(n>2){
        for(int i=1;i<n;i++){
            if(vec[i] <= mn){
                mn = vec[i];
                currRes = min(currRes, (long long int)floor( mn/i ) );
                if(mn < vec[n-1]){
                    currRes = min(currRes, (long long int)floor(mn/ (n-i-1) ));
                }
            }
        }
    }
    cout << currRes << endl;
    return 0;
}
