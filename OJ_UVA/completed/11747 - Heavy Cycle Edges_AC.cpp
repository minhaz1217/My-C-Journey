/*
    was getting WA because had myQ as vector pair pair, but myQ[0] was returning the value of myQ[0].first in my compiler
    and not in the OJ's
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


class disjoint_set{
private:
    vector<long long int>p,rt;
public:
    disjoint_set(long long int n){
        n+=2;
        p.assign(n, 0);
        rt.assign(n, 0);
        for(long long int i=0;i<n;i++){
            p[i] = i ;
        }
    }
    long long int findSet(long long int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] = findSet(p[x]);
        }
    }
    bool isSameSet(long long int x,long long int y){
        return findSet(x) == findSet(y);
    }
    void unionSet(long long int x, long long int y){
        if(!isSameSet(x,y)){
            long long int a,b;
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
    long long int n,m,sz,i,j,u,v,w;
    while(1){
        scanf("%lld%lld", &n, &m);
        vector<pair<long long int, pair<long long int, long long int> > >edges;
        vector<long long int>myQ;
        if(n == 0 && m == 0){
            break;
        }
        disjoint_set dj(n);

        for(i=0;i<m;i++){
            scanf("%lld%lld%lld", &u, &v , &w);
            edges.push_back(make_pair(w, make_pair(u,v)));
        }
        sort(edges.begin(), edges.end());
        sz = edges.size();
        for(i =0;i<sz;i++){
            u = edges[i].second.first;
            v = edges[i].second.second;
            w = edges[i].first;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
            }else{
                myQ.push_back(edges[i].first);
            }
        }
        if(myQ.size() == 0){
            printf("forest\n");
        }else{
            sort(myQ.begin(), myQ.end());
            //reverse(myQ.begin(), myQ.end());
            sz = myQ.size();
            printf("%lld", myQ[0]);
            for(i=1;i<sz;i++){
                printf(" %lld", myQ[i]);
            }
        printf("\n");
        }

    }
    //printf("\n");

    return 0;
}
