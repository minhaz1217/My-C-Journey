/*
Minhazul Hayat Khan
EWU
Problem Name: 10600 - ACM Contest and Blackout
Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1541
Date : 28 / February / 2018
Comment: somewhat hard mst, had to run n mst to find second best mst solution.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n, 0);
        rt.assign(n, 0);
        for(int i=0;i<n;i++){
            p[i] = i ;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] = findSet(p[x]);
        }
    }
    bool isSameSet(int x,int y){
        return findSet(x) == findSet(y);
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
int main(){
    int tc,n,m,u,v,w,sz,i,k,cost2, cost1,counter,j,found,flag,minCost,sCost;

    scanf("%d", &tc);
    while(tc--){
        vector<pair<int, pair<int,int> > >edges;
        vector<pair<int,int> > minMst;
        scanf("%d%d", &n, &m);
        for(k=0;k<m;k++){
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(make_pair(w, make_pair(u,v)));
        }
        disjoint_set dj(n+1);
        sort(edges.begin(), edges.end());
        sz = edges.size();
        cost1 = 0;
        for(i=0;i<sz;i++){
            u = edges[i].second.first;
            v = edges[i].second.second;
            w = edges[i].first;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                //msg2(u,v,w)
                cost1 += w;
                minMst.push_back(make_pair(u,v));
            }
        }
        sz = edges.size();
        minCost = INT_MAX;
        for(j=0;j<sz;j++){
            cost2 = 0;
            counter = 0;
            found = 0;
            disjoint_set dj2(n+1);
        vector<pair<int,int> > minMst2;
            for(i=0;i<sz;i++){
                if(i==j){
                    continue;
                }
                u = edges[i].second.first;
                v = edges[i].second.second;
                w = edges[i].first;
                if(!dj2.isSameSet(u,v)){
                    dj2.unionSet(u,v);
                    cost2 += w;
                    counter++;
                    minMst2.push_back(make_pair(u,v));
                }
                if(counter == n-1){
                    found = 1;
                    break;
                }
            }
            if(found == 1){
               // msg(cost2, minCost)
                if(minCost >= cost2 && minMst != minMst2){
                    sCost = minCost;
                    minCost = cost2;
                }
            }
        }
        printf("%d %d\n", cost1, minCost);

    }

    return 0;
}
