#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


struct edge{
    int u,v,w;
    edge(int uu, int vv, int ww){
        u = uu;
        v = vv;
        w = ww;
    }
};

class disjoint_set{
    vector<int> p, rt;
public:
    disjoint_set(int n){
        n++;
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
        return findSet(x) == findSet(y);
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a = findSet(x), b = findSet(y);
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
bool operator<(edge a, edge b){
    return a.w<b.w;
}

int main(){

    int n,m,u,v,w,k,i,cost, cost1, sz,counter =1;
    while(scanf("%d", &n) == 1){
        vector<edge>edges;
        disjoint_set dj(n);
        cost1 = 0;
        for(i=1;i<n;i++){
            scanf("%d%d%d", &u, &v, &w);
            cost1 += w;
        }
        scanf("%d", &k);
        while(k--){
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(edge(u,v,w));
        }
        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(edge(u,v,w));
        }
        sort(edges.begin(), edges.end());
        sz = edges.size();
        cost = 0;
        for(i=0;i<sz;i++){
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                cost += w;
            }
        }
        if(counter > 1){
            cout << endl;
        }
        counter++;
        cout << cost1 << endl << cost << endl;
    }



    return 0;
}
