#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc, i,j,k, u,v,n;
    cin >> tc;
    while(tc--){
        cin >> n;
        int p[n+2] = {0};
        vector<int> mat[n+2];
        bool  visited[n+2] = {0};
        int d[n+2] = {0};

        for(i=1;i<=n;i++){
            cin >> u >> v;
            mat[v].push_back(u);
            //mat[u].push_back(v);
            p[v] = u;
        }


        queue<int> q;

        for(i=1;i<=n;i++){
            //int visited[n+2] = {0};
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                d[i] += d[p[i]] +1 ;
                while(!q.empty()){
                    u = q.front();
                    //msg(u, d[u])
                    q.pop();
                    visited[u] = 1;
                    for(j=0;j<mat[u].size();j++){

                        //msg(u,j)
                        v = mat[u][j];

                        //msg("This", v)
                        if(visited[v] == 0){
                            d[v] = d[u]+1;
                            q.push(v);
                            //msg(v, d[v])
                        }else{
                            d[u] += d[v];
                        }
                    }


                }
            }
        }
    for(i=1;i<=n;i++){
        check(d[i])
    }


    }

    return 0;
}
