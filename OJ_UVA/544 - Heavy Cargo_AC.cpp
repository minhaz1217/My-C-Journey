#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define INF 5000000
struct edge{
    int u,v,w;
    edge(int uu, int vv, int ww){
        u = uu;
        v = vv;
        w = ww;
    }
};
class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        n = n+1;
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
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    int isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    int unionSet(int x, int y){
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

bool operator<(edge a, edge b){
    return a.w < b.w;
}


int main(){

    int n,m,s,d,city,i,cost,sz,u,v,w,ww,caseCounter = 1;
    string city1, city2;
    while(1){
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0){
            break;
        }
        //msg(n,m)
        city = 1;
        vector<edge>edges;
        vector<int>visited;
        queue<pair<int, int> > q;
        map<string, int>mp;
        vector<pair<int,int> > vec[n+4];
        pair<int, int> f;
        disjoint_set dj(n);
        //cc("HI")
        while(m--){
            cin >> city1  >> city2 >> w;
            //scanf("%s %s %d", &city1, &city2, &w);
            //msg2(city1, city2, w)
            if(!mp[city1]){
                mp[city1] = city++;
            }
            if(!mp[city2]){
                mp[city2] = city++;
            }
            edges.push_back(edge(mp[city1], mp[city2], w));
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        cost =0;
        sz = edges.size();
        for(i=0;i<sz;i++){
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                vec[u].push_back(make_pair(v,w));
                vec[v].push_back(make_pair(u,w));
            }
        }
        cin >> city1 >> city2;
        //scanf("%s%s", &city1, &city2);
        s = mp[city1];
        d = mp[city2];
        q.push(make_pair(s,INF));
        visited.assign(n+1, 0);
        visited[s] = 1;
        while(!q.empty()){
            f = q.front();
            u = f.first;
            w = f.second;
            q.pop();
            if(u == d){
                cost = w;
                break;
            }
            for(i = 0; i< vec[u].size();i++){
                v = vec[u][i].first;
                ww = vec[u][i].second;
                if(!visited[v]){
                    q.push(make_pair(v,min(w,ww)));
                    visited[v] = 1;
                }
            }

        }
        printf("Scenario #%d\n%d tons\n", caseCounter++, cost);
        if(caseCounter>1){
            printf("\n");
        }


    }
    return 0;
}
