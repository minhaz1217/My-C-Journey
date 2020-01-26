/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 20 / January / 2020
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
#define MX 100005
vector<map<int,int> > vecc;
int main(){
    _INIT;
    long long int n,m,x,l,r,val,v1,k1,mx;
    while(1){
        map<int,int> mp,mp1,mp2;
        map<pair<int,int> , int> query;
        vecc.clear();
        cin >> n;
        if(n ==0){
            break;
        }
        cin >> m;
        vecc.push_back(mp);
        for(int i=0;i<n;i++){
            cin >> x;
            if(mp.find(x) == mp.end()){
                mp[x] = 1;
            }else{
                mp[x]++;
            }
            vecc.push_back(mp);
        }
        while(m--){
            cin >> l >> r;
            if(! (query.find({l,r}) == query.end()) ){
                cout << query[{l,r}] << endl;
                break;
            }
            mp1 = vecc[l-1];
            mp2 = vecc[r];
            mx = 0;
            for(auto it: mp2){
                k1 = it.first;
                v1 = it.second;
                if( mp1.find(k1) == mp1.end() ){
                    val = v1;
                }else{
                    val = v1 - mp1[k1];
                }
                mx = max(mx, val);
            }
            cout << mx << endl;
            query[ {l,r} ] = mx;
        }
    }
    return 0;
}
