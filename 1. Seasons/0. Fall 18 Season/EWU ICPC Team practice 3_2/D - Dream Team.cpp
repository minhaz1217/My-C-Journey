#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

vector<pair< long long int, pair<long long int, long long int> > >edgelist;

vector<int>vec,vec2;
map<int,int>mp;
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
    reverse(edgelist.begin(),edgelist.end());
    sz = edgelist.size();
    mst_cost = 0;
    //cc("HI")
    for(long long int i=0;i<sz;i++){
        u = edgelist[i].second.first;
        v = edgelist[i].second.second;
        //msg(u,v)
        if(!dj.isSameSet(u,v)){
            //msg3("CONNECTED", u,v,edgelist[i].first)
            //msg2(vec2[u] ,vec2[v], edgelist[i].first)
            dj.unionSet(u,v);
            mst_cost += edgelist[i].first;
        }
    }
    //msg("COST", mst_cost)
    return mst_cost;

}


int main(){
    int m,u,v,w,tc,n,a,nodes = 1;

    cin >> tc;
    while(tc--){
        vec.clear();
        vec2.clear();
        mp.clear();
        edgelist.clear();
        vec2.push_back(-1);
        nodes = 1;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
            if(!mp[a]){
                mp[a] = nodes++;
                vec2.push_back(a);
            }
        }
        //msg("@D", vec2.size())
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                u = vec[i];
                v = vec[j];
                w = __gcd(u,v);
               // msg2(u,v,w)

                u = mp[u];
                v = mp[v];
                //msg3("MEH", u,v,w)
                edgelist.push_back(make_pair(w, make_pair(u,v)));
            }
        }
        //msg("SIZE", edgelist.size())
        //msg("NODES", nodes)
        for(int i=0;i<edgelist.size();i++){
            //msg2(edgelist[i].first, edgelist[i].second.first, edgelist[i].second.second)
        }
        cout << "COST: " << kruskal(nodes+1) << endl;
    }





    return 0;
}
