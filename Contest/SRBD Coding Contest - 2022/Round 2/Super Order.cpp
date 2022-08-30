/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link:
Complexity:
Date : 30 / Aug / 2022

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



//msg kruskal
vector<pair< long long int, pair<long long int, long long int> > >edgelist;

class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
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
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }

};

long long int kruskal(int n){
    // if 0-index then dj start with n otherwise n+1
    long long int sz, mst_cost,u,v;
    disjoint_set dj(n);
    sort(edgelist.begin(), edgelist.end());
    sz = edgelist.size();
    mst_cost = 0;
    for(long long int i=0;i<sz;i++){
        u = edgelist[i].second.first;
        v = edgelist[i].second.second;
        if(!dj.isSameSet(u,v)){
            dj.unionSet(u,v);
            mst_cost += edgelist[i].first;
        }
    }
    return mst_cost;

}

int main(){
    _INIT;
    int tc,n,m,a,b;
    cin >> tc;
    while(tc--){
        double vulnerableEdge =0, connected = 0;
        cin >> n >> m;


        disjoint_set dj(n+4);

        for(int i=1;i<=m;i++){
            cin >> a >> b;

            if(indegree[a] == 0 && indegree[b] == 0){
                vulnerableEdge++;
            }else if(indegree[a] == 0 || indegree[b] == 0){
                vulnerableEdge++;
            }

            if(indegree[a] == 1 && indegree[b] == 1){
                vulnerableEdge--;
            }


            indegree[a]++;
            indegree[b]++;
            msg(vulnerableEdge, i)
            cout << vulnerableEdge / i << endl;
        }
    }
    return 0;
}
