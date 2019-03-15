/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1138/problem/A
Date : 15 / March / 2019
Comment: easy problem if the problem statement is read carefully.
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
    long long int n,counter,prev,a,currMax;
    vector<long long int>vec,vec2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    prev = vec[0];
    counter = 1;
    for(int i=1;i<n;i++){
        if(vec[i] != prev){
            vec2.push_back(counter);
            prev = vec[i];
            counter = 1;
        }else{
            counter++;
        }
    }
    vec2.push_back(counter);

    currMax = 0;
    for(int i=1;i<vec2.size();i++){
        //msg(i,vec2[i])
        currMax = max(min(vec2[i], vec2[i-1]),currMax);
    }
    cout << currMax*2 << endl;


    return 0;
}
