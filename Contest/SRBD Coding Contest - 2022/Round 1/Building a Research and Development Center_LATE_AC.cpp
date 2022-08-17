/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center
Complexity:
Date : 16 / Aug / 2022

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

map<int,int> mp;

//DISJOINT SET
class disjoint_set{
public:
    vector<int>p;
    vector<pair<int,int> > rt; // first one will keep track of seniority second will keep track of senior's id.
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,make_pair(0,0));
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a].first > rt[b].first){
                // b will merge into a
                p[b] = a;
            }else{
                // a will merge into b
                p[a] = b;
                if(rt[a].first == rt[b].first){
                    if(rt[a].second >= rt[b].second){
                        rt[b].second = rt[a].second;
                    }
                }
            }
        }
    }
    int findSeniorId(int x){
        //msg("Set", findSet(x))
        return rt[ findSet(x) ].second;
    }
    void promote(int x){
        mp[x]++;
        int groupLeader = findSet(x);
        if(rt[groupLeader].first < mp[x]){ // x is the equal or same rank as group leader
            rt[groupLeader].first = mp[x];
            rt[groupLeader].second = x;
        }else if(rt[groupLeader].first == mp[x]){
            rt[groupLeader].second = max(x, rt[groupLeader].second); // now x is the senior.
        }
    }

};

disjoint_set dj(100010);
int main(){
    _INIT;
    int tc,q,a,b;
    cin >> tc >> q;
    while(tc--){
        cin >> a;
        dj.rt[a] = make_pair(tc+1, a);
        mp[a] = tc+1;
    }


    while(q--){
        cin >> a;
        if(a == 1){
            cin >> a >> b;
            dj.unionSet(a,b);
        }else if(a == 2){
            cin >> a;
            dj.promote(a);
        }else if(a==3 || a== 0){
            cin >> a;
            //cout << mp[a] << endl;
            cout << dj.findSeniorId(a) << endl;
        }
    }
    return 0;
}
