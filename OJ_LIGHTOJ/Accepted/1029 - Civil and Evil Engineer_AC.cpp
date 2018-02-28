#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w){
        u= _u;
        v= _v;
        w = _w;
    };
};
class disjoint{
protected:
    vector<int>p,rk;
    public:
    disjoint(int n){
        p.assign(n,0);
        rk.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
    int unionSet(int x, int y){
        int px,py;
        px = findSet(x);
        py = findSet(y);
        if(px != py){
            if(rk[px] > rk[py]){
                p[py] = px;
            }else{
                p[px] = py;
                if(rk[px] == rk[py]){
                    rk[py]++;
                }
            }
        }
    }
    int isSameSet(int x, int y){
        if(findSet(x) == findSet(y)){
            return 1;
        }else{
            return 0;
        }
    }



};

int main(){
    int tc,u,v,w,i,n,cost, maxCost,caseCounter = 1;
    pair<int, pair<int,int> >f;
    cin >> tc;
    while(tc--){
        vector<pair<int,pair<int,int> > > edges;

        cin >> n;
        disjoint dj(n+1), dj2(n+1);
        while(1){
            cin >> u >> v >> w;
            if(u == 0 && v ==0 && w == 0){
                break;
            }
           //edges.push_back({w,{u,v});
           edges.push_back(make_pair(w, make_pair(u,v)));
        }
        sort(edges.begin(), edges.end());
        cost = 0;
        //msg("HI", edges.size())
        for(i=0;i<edges.size();i++){
            f = edges[i];
            w = f.first;
            u = f.second.first;
            v = f.second.second;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                cost += w;
            }
        }
        //cout << cost << endl;
        reverse(edges.begin(), edges.end());

        maxCost = 0;
        //msg("HI", edges.size())
        for(i=0;i<edges.size();i++){
            f = edges[i];
            w = f.first;
            u = f.second.first;
            v = f.second.second;
            if(!dj2.isSameSet(u,v)){
                dj2.unionSet(u,v);
                maxCost += w;
            }
        }
        //cc(maxCost)
        cost = maxCost + cost;
        if(cost%2 == 0){
            cout << "Case " << caseCounter++ << ": " << cost/2 << endl;

        }else{
            cout << "Case " << caseCounter++ << ": " << cost << "/2" << endl;

        }
        //cout << "Case " << caseCounter++ << ": " << (maxCost+cost)/2 << endl;
    }



    return 0;
}
