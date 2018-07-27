#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 504
int mat[MX][MX];
struct edge{
    int u,v,w;
    edge(int uu=0, int vv=0, int ww=0){
        u = uu;
        v = vv;
        w = ww;
    }
};

bool operator<(edge a, edge b){
    return a.w<b.w;
}

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


int main(){
    int tc,n,m,cost,i,j,u,v,w,caseCounter=1,INF=10000000,t,temp;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &n, &m);
        vector<edge>vec;
        vector<int>graph[n+4],p;
        queue<int>q;
        disjoint_set dj(n);
        for(i=0;i<n;i++){
            p.push_back(i);
            for(j=0;j<n;j++){
                mat[i][j] = INF;
            }
            mat[i][i] = 0;
            //p[i] = i;
        }
        while(m--){
            scanf("%d%d%d", &u,&v,&w);
            vec.push_back(edge(u,v,w));
        }
        sort(vec.begin(), vec.end());
        cost = 0;
        for(i=0;i<vec.size();i++){
            u = vec[i].u;
            v = vec[i].v;
            w = vec[i].w;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                cost+=w;
                //msg(u,v)

                graph[u].push_back(v);
                graph[v].push_back(u);
                mat[u][v] = w;
                mat[v][u] = w;
            }
        }
        //cc("HI")
        scanf("%d", &t);
        q.push(t);
        vector<int>visited,weight;
        visited.assign(n+4,0);
        //p.assign(n,-1);
        weight.assign(n+4,0);
        visited[t] = 1;
        //cc("HI")
        while(!q.empty()){
            u = q.front();
            //cc(u)
            q.pop();
            for(i=0;i<graph[u].size();i++){
                //cc("HELLO")
                //cc(graph[u].size())
                v= graph[u][i];
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                    p[v] = u;
                    //msg(v,u)
                }
            }
        }
        //cc("HI")

        for(i=0;i<n;i++){
            //msg(i,p[i])
            temp = i;
            while( !(temp==t || p[temp] == temp )){
                weight[i] = max(weight[i], mat[temp][p[temp]]);
                temp = p[temp];
            }
        }
        printf("Case %d:\n", caseCounter++);
        //cout << "Case "<< caseCounter++ << ":" << endl;

        for(i=0;i<n;i++){
            if(dj.isSameSet(t,i)){
                //cc("HOLA")
                printf("%d\n", weight[i]);
            }else{
                printf("Impossible\n");
            }
        }


    }

    return 0;
}
