/*
Minhazul Hayat Khan
EWU
Problem Name: 1123 - Trail Maintenance
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1123
Date : 27 / February / 2018
Comment: there is a trick, but funny problem. MST.
*/
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
        p.assign(n+1, 0);
        rt.assign(n+1,0);
        for(int i=1;i<=n;i++){
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
    void reset(int n){
        for(int i=1;i<=n;i++){
            p[i] = i;
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
    int tc,n,m,caseCounter = 1,szz,u,v,w,i,j,cost,foundAll,sz,counter,changed,mark;
    //cin >> tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        disjoint_set dj(n);
        //cin >> n >> m;
        //cout << "Case "<< caseCounter++ << ":" << endl;
        printf("Case %d:\n",caseCounter++);
        vector<edge>pq,mst;
        set<int>st;
        while(m--){
            //cin >> u >> v >> w;
            scanf("%d%d%d", &u,&v,&w);

            st.insert(u);
            st.insert(v);

            changed = 0;
            pq.push_back(edge(u,v,w));

            szz = st.size();
            if(szz==n){
                sort(pq.begin(), pq.end());
                dj.reset(n);
                sz = pq.size();
                cost = 0;
                mark++;
                counter = 0;
                for(i=0;i<sz;i++){
                    w = pq[i].w;
                    u = pq[i].u;
                    v = pq[i].v;
                    if(!dj.isSameSet(u,v)){
                        dj.unionSet(u,v);
                        cost += w;
                        mst.push_back(edge(u,v,w));
                    }
                }
                if(mst.size() != n-1){
                    cost = -1;
                }
                pq.clear();
                pq = mst;
                mst.clear();
            }else{
                cost = -1;
            }
            printf("%d\n", cost);
            //cout << cost << endl;


        }
    }
    return 0;
}
