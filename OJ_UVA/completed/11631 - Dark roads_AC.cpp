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
            p[i] = i;
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
    long long int n,m,u,v,w,cost,i,sz,sum;
    while(1){
        scanf("%lld%lld", &n, &m);
        if(n==0 && m==0){
            break;
        }
        vector<pair<int, pair<int,int> > >edges;

        disjoint_set dj(n);
        sum = 0;
        for(i=0;i<m;i++){
            cin >> u >> v >> w;
            sum += w;
            edges.push_back(make_pair(w, make_pair(u,v)));
        }
        //cc(edges.size())
        sort(edges.begin(), edges.end());
        sz = edges.size();
        cost= 0;
        for(i=0;i<sz;i++){
            u = edges[i].second.first;
            v = edges[i].second.second;
            w = edges[i].first;
            if(!dj.isSameSet(u,v)){
                cost += w;
                dj.unionSet(u,v);
            }
        }
        printf("%lld\n", sum-cost);
    }


    return 0;
}
