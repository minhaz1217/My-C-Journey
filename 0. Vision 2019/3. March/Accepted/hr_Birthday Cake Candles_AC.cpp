/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.hackerrank.com/challenges/birthday-cake-candles/problem
Date : 06 / March / 2019
Comment: Very easy problem. Solved it .. just because...
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
    long long int a,n,counter,curr;
    vector<long long int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    curr = vec[vec.size()-1];
    counter = 1;
    for(int i=vec.size()-2;i>=0;i--){
        if(vec[i] != curr){
            break;
        }
        counter++;
    }
    cout << counter << endl;
    return 0;
}
