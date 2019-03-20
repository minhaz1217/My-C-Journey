/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: http://codeforces.com/contest/1141/problem/B
Date : 20 / March / 2019
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
#define mod 41
#define pp 29
int main(){
    long long int n,a,counter, mx,countere,counterb;
    vector<int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    counter = 0;
    mx = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] == 1){
            counter++;
        }else{
            mx = max(counter, mx);
            counter = 0;
        }
    }
    counterb = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] !=1){
            break;
        }else{
            counterb++;
        }
    }
    countere = 0;
    for(int i=vec.size()-1;i>=0;i--){
        if(vec[i] !=1){
            break;
        }else{
            countere++;
        }
    }
    mx = max(mx, countere+counterb);
    cout << mx << endl;
    return 0;
}
