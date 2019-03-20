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
    long long int n,a,mn,ad,mx,flag;
    vector<long long int>vec,vec2,vec3;
    cin >>n;
    map<int, int>mp;
n--;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    vec2.push_back(1);
    mn = INT_MAX;
    for(int i=0;i<vec.size();i++){
        vec2.push_back(vec2[i]+vec[i]);
        mn = min(mn, *(vec2.end()-1) );
    }
//    for(int i=0;i<vec2.size();i++){
//        cout << vec2[i] << " ";
//    }
//    cout << endl;
    if(mn<= 0){
        ad = mn*-1 + 1;
    }else{
        ad = 0;
    }
    //msg(mn,ad)
    mx = INT_MIN;
    flag = 0;
    for(int i=0;i<vec2.size();i++){
        a = vec2[i]+ad;
        if(a>n+1){
            flag = 1;
            break;
        }
        vec3.push_back(a);
        if(mp.find(a) == mp.end()){
            mp[a] = 1;
        }else{
            flag = 1;
            break;
        }
    }
    //msg("MS", mx)
    if(flag == 1){
        cout << -1 << endl;
    }else{
        for(int i=0;i<vec3.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << vec3[i] ;
        }
    }
    return 0;
}
