/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 17 / February / 2019
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


int main(){
    long long int n,sum = 0, a,currLen=0, len = 0, currSum, currMax;
    vector<long long int>vec;
    cin >> n;
    currMax = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        currMax = max(a, currMax);
        vec.push_back(a);
    }
    for(int i=0;i<n;i++){
        if(vec[i] == currMax){
            len++;
        }else{
            currLen = max(len , currLen);
            len = 0;
        }
    }
            currLen = max(len , currLen);
    cout << currLen << endl;
    return 0;
}
