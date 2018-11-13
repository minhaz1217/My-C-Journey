#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

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
    int m,u,v,w;
    edgelist.push_back(make_pair(1, make_pair(1,2)));
    edgelist.push_back(make_pair(1, make_pair(2,3)));
    edgelist.push_back(make_pair(1, make_pair(3,4)));
    edgelist.push_back(make_pair(1, make_pair(1,4)));
    cout << kruskal(5) << endl;
    //output 3
/*
3
*/
   return 0;
}
