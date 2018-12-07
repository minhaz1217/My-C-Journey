#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

vector<pair< long long int, pair<long long int, long long int> > >edgelist;
int mat[504 ][504 ];
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
    int m,u,v,w,mst_cost,n,sz,mainCost,bu,bv,cost = 0, totalCost = 0,rp =0, nodes = 0;
    vector<pair<int, int> > tree;
    set<pair<int,int> > replaceMent;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        mat[u][v] = w;
        totalCost += w;
        edgelist.push_back(make_pair(w, make_pair(u,v)));
    }


    disjoint_set dj(n+1);
    sort(edgelist.begin(), edgelist.end());
    sz = edgelist.size();
    mst_cost = 0;
    nodes = 0;
    for(long long int i=0;i<sz && nodes < n-1;i++){
        u = edgelist[i].second.first;
        v = edgelist[i].second.second;
        if(!dj.isSameSet(u,v)){
            dj.unionSet(u,v);
            nodes++;
            tree.push_back(make_pair(u,v));
            mst_cost += edgelist[i].first;
        }
    }
    //msg("MAIN", mst_cost)
    mainCost = mst_cost;

    for(int k=0;k<tree.size();k++){
        bu = tree[k].first;
        bv = tree[k].second;
        disjoint_set dj2(n+1);
        mst_cost = 0;
        nodes = 0;

        for(long long int i=0;i<sz && nodes<n-1;i++){
            u = edgelist[i].second.first;
            v = edgelist[i].second.second;
            //msg(u,v)
            if( !(bu == u && bv == v) ){
                if( !dj2.isSameSet(u,v)){
                    dj2.unionSet(u,v);
                    //msg2("REPLACEMENT", u,v)
                    //tree.push_back(u,v);
                    mst_cost += edgelist[i].first;
                    nodes++;
                    //cc("HI")
                }
                if(nodes == n-1){
                    break;
                }
            }

        }
        if(mainCost != mst_cost){
            //replaceMent.insert(make_pair(bu,bv));
            rp++;
            cost += mat[bu][bv];

        }
        //msg3(bu,bv,mainCost, mst_cost)

    }
    // cout << edgelist.size() - rp << " " << totalCost - cost << endl;
     cout <<  rp << " " <<  cost << endl;
    return 0;
}
