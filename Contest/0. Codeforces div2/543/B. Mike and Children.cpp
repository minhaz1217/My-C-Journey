/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 03 / March / 2019
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
    int n,a,mx;
    vector<int>vec,vec2;
    map<int,int>mp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            a= vec[i] + vec[j];
            if(!mp[a]){
                mp[a] =1;
                vec2.push_back(a);
            }else{
                mp[a]++;
            }
        }
    }
    mx = INT_MIN;
    for(int i=0;i<vec2.size();i++){
        mx = max(mx, mp[ vec2[i] ])   ;
    }
    cout << mx << endl;
    return 0;
}
