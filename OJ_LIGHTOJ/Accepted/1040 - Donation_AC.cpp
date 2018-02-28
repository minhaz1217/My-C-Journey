#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
struct edge{
    int u,v,w;
    edge(int _u=0, int _v=0,int _w=0){
         u = _u;
         v = _v;
         w = _w;
    }

};
    bool operator<(edge b, edge a){
        return b.w < a.w;
    }
class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n+1,0);
        rt.assign(n+1,0);
        //msg("Size", p.size())
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
    int isSameSet(int x, int y){
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

    //cout <<  (e2 < e1) << endl;

    int tc,caseCounter=1,counter , cost,n,i,j,u,v,w,sum;
    edge k;
    cin >> tc;
    while(tc--){
        cin >> n;
        disjoint_set dj(n);
        vector<edge>edges;
        sum = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin >> w;
                if(w>0){
                    sum += w;
                    edges.push_back(edge(i,j,w));
                }
            }
        }
        sort(edges.begin(), edges.end());
        cost = 0;
        for(i=0;i<edges.size();i++){
            k = edges[i];
            u = k.u;
            v = k.v;
            w = k.w;
            if(!dj.isSameSet(u,v)){
                //msg2(u,v,w)
                dj.unionSet(u,v);
                cost += w;
            }
        }
        counter = 0;
        for(i=1;i<=n;i++){
            if(dj.findSet(i) == i){
                counter++;
            }
        }
        if(counter > 1){
            sum = -1;
            cost = 0;
        }
        cout << "Case " << caseCounter++ << ": " << (sum-cost) << endl;
        //cout << cost << endl;
        //cc(sum - cost)

    }


    return 0;
}
