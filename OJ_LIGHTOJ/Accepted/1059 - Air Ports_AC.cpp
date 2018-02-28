#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

struct edge{
    int u,v,w;
    edge(int uu = 0, int vv =0, int ww = 0){
        u = uu;
        v = vv;
        w = ww;
    }



};
bool operator<(edge b, edge a){
    return b.w < a.w;
}
class disjoint_set{
private:
    vector<int>p, rt;
public:
    disjoint_set(int n){
        p.assign(n+1, 0);
        rt.assign(n+1, 0);
        for(int i=0;i<=n;i++){
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

    int tc,n,m,a,u,v,w,cost,airPorts, counter, caseCounter = 1,i;
    edge f;
    cin >> tc;
    while(tc--){
        cin >> n >> m >> a;
        disjoint_set dj(n);
        vector<edge>edges;
        while(m--){
            cin >> u >> v >> w;
            edges.push_back(edge(u,v,w));
        }
        sort(edges.begin(), edges.end());
        cost = 0;
        airPorts = 0;
        for(i=0;i<edges.size();i++){
            f = edges[i];
            u = f.u;
            v = f.v;
            w = f.w;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                if(w >= a){
                    airPorts++;
                }else{
                    cost += w;
                }

            }
        }
        counter =0;
        for(i=1;i<=n;i++){
            if(dj.findSet(i) == i){
                counter++;
            }
        }
        airPorts += counter;
        cost = cost + a*airPorts;
        cout << "Case "<< caseCounter++ << ": " << cost << " " << airPorts<< endl;



    }

    return 0;
}
