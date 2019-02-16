/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/283774#problem/B
https://www.spoj.com/problems/AIBOHP/en/
Date : 16 / February / 2019
Comment: Very basic DP.
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
#define MX 6200
#define mymax 9999999
string str;
int dp[MX][MX];
int counter;
int dps(int l, int r){
    if(l>=r){
        return 0;
    }
    if(dp[l][r] != mymax){
        return dp[l][r];
    }
    int d1,d2,d3;

    if(str[l] == str[r]){
        dp[l][r] = 0 + dps(l+1, r-1);
    }else{
        d1= 1+dps(l+1,r);
        d2 = 1+dps(l, r-1);
        d3 = 2 + dps(l+1,r-1);
        dp[l][r] = min(d1,min(d3,d2));
    }
    return dp[l][r];
}


int main()
{
    int tc;

    cin >> tc;
    while(tc--){
        cin >> str;
        for(int i=0;i<str.size()+4;i++){
            for(int j=0;j<str.size()+4;j++){
                dp[i][j] = mymax;
            }
        }
        dps(0,str.size()-1);
        /*
        for(int i=0;i<str.size()+2;i++){

            for(int j=0;j<str.size()+2;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        int myD = dp[0][str.size()-1];
        cout << myD << endl;
    }
    return 0;
}
