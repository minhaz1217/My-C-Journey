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
bool operator<(edge a, edge b){
    return a.w<b.w;
}

class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n, 0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] =findSet(p[x]);
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
    int tc,cost,n,m,k,u,v,w,i,caseCounter = 1;
    scanf("%d", &tc);
    while(tc--){

        scanf("%d %d %d", &n, &m,&k);
        vector<edge>edges;
        vector<int>visited,vec;
        disjoint_set dj(n);
        visited.assign(n,0);
        while(m--){
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(edge(u,v,w));
        }
        sort(edges.begin(), edges.end());
        visited[k] = 1;
        cost = 0;
        for(i=0;i<edges.size();i++){
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
            if(!dj.isSameSet(u,v)){
                if(visited[u] == 1){
                    dj.unionSet(u,v);
                    cost+=w;
                    visited[v] = 1;
                    msg2(u,v,w)
                    vec.push_back(w);
                    i = -1;
                    continue;
                }
            }
        }
        //msg(vec.size(), cost)
        //cout << cost << endl;
        if(cost ==0 || vec.size() != n-1){
            cout << "Case "<< caseCounter++ << ": impossible" << endl;
        }else{
            cout << "Case "<< caseCounter++ << ": " << cost << endl;

        }

    }

    return 0;
}
