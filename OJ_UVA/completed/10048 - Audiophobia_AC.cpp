#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104
int mat2[MX][MX];

class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n, 0);
        rt.assign(n, 0);
        for(int i=0;i<n;i++){
            p[i] = i ;
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
    int c,s,qq,u,v,w,ww,i,j,sz,myBig,counter,caseCounter = 1, ta = 1,temp,t,cost;

    while(1){


        scanf("%d%d%d", &c, &s,&qq);
        if(c== 0&& s == 0&& qq==0){
            break;
        }
        if(ta>1){
            printf("\n");
        }
        ta++;
        printf("Case #%d\n", caseCounter++);
        disjoint_set dj(c+1);
        vector<pair<int, pair<int,int> > >edges;
        vector<int>mat[c+1];
        pair<int, int>f;
        for(i=0;i<s;i++){
            scanf("%d%d%d", &u, &v, &w);
            edges.push_back(make_pair(w, make_pair(u,v)));
        }
        sort(edges.begin(), edges.end());
        sz = edges.size();
        counter = 0;
        cost = 0;
        for(i=0;i<sz;i++){
            u = edges[i].second.first;
            v = edges[i].second.second;
            w = edges[i].first;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                mat[u].push_back(v);
                mat[v].push_back(u);
                //mat[u].push_back(make_pair(v,w));
                //mat[v].push_back(make_pair(u,w));
                mat2[u][v] = w;
                mat2[v][u] = w;
                //mat[v].push_back(u);
                cost += w;
                counter++;
            }
            if(counter == c-1){
                break;
            }
        }
        //msg("COST", cost)
        for(i=0;i<qq;i++){
            scanf("%d%d", &s, &t);
            if(dj.isSameSet(s,t)){
            vector<int> visited;
            int p[c+1];
            visited.assign(c+1,0);
            queue<int>q;
            q.push(s);
            visited[s] = 1;

            while(!q.empty()){
                u = q.front();
                //cc(u)
                q.pop();
                if(u == t){
                    break;
                }

                for(j=0;j<mat[u].size();j++){
                    v = mat[u][j];
                    if(!visited[v]){
                        q.push(v);
                        p[v] = u;
                        visited[v] = 1;
                    }
                }
            }
            temp = t;
            myBig = INT_MIN;
            while(temp != s){
                myBig = max(myBig, mat2[temp][p[temp]]);
                temp = p[temp];
            }
            printf("%d\n", myBig);
            }else{
                printf("no path\n");
            }

        }


    }
    return 0;
}
