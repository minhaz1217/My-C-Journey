/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://abc106.contest.atcoder.jp/tasks/abc106_d?lang=en
Date : 17 / May / 2019
Comment: binary search.
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

    long long int n,m,q,u,v,l,r,sum;
    cin >> n >> m >> q;
    vector<long long int> vec[n+2];
    map<pair<long long int, long long int>,long long int > mp;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        //vec.push_back(make_pair(u,v));
        vec[u].push_back(v);
    }
    //sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end());
    }
    for(int l=0;l<q;l++){
        cin >> u >> v;
        sum = 0;
        if(mp.find(make_pair(u,v)) != mp.end()  ){
            cout << mp[make_pair(u,v)]  << endl;
            continue;
        }
        for(int i=u;i<=v;i++){
            r = upper_bound(vec[i].begin(),vec[i].end(), v)-vec[i].begin();
            sum += r;
        }
        mp[ make_pair(u,v)] = sum;
        //msg("ANS", sum)
        cout << sum << endl;
    }
    return 0;
}
