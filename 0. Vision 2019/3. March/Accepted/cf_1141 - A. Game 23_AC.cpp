/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: http://codeforces.com/contest/1141/problem/A
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

    long long int n, m,counter, t;
    cin >>n >> m;
    vector<int>vec;
    vec.push_back(2);
    vec.push_back(3);
    counter = 0;
    if(m%n == 0){
        t = m/n;
        for(int i=0;i<vec.size();i++){
            while(t%vec[i] == 0){
                t = t/vec[i];
                counter++;
            }
        }
        //cc(t)
        if(t!=1){
            cout << -1 << endl;
        }else{
            cout << counter << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}
