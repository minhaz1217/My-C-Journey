#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 100005
int p[MX],cc[MX],visited[MX];
int main(){
    int tc,n,u,v,t,temp,i,j,sum,caseCounter = 1;
    queue<int>q;

    scanf("%d", &tc);
    //cin >> tc;
    while(tc--){
        scanf("%d", &n);
        vector<int> mat[n+4];
        //cin >> n;
        for(i=0;i<=n;i++){
            p[i] = -1;
            cc[i] = 0;
            //mat[i].clear();
            visited[i] = 0;
        }
        for(i=1;i<n;i++){
            scanf("%d %d", &u, &v);
            //cin >> u >> v;
            mat[u].push_back(v);
            mat[v].push_back(u);
            //mat[u][v] = 1;
            //mat[v][u] = 1;
        }

        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(i=0;i<mat[u].size();i++){
                t = mat[u][i];
                if(!visited[t]){
                    p[t] = u;
                    temp = t;
                    while(p[temp]!= -1){
                        cc[t]++;
                        cc[p[temp]]++;
                        temp = p[temp];
                        //msg(t, temp)
                    }
                    /*
                    if(mat[t].size() > 1){
                        for(j=0;j<mat[t].size();j++){
                            if(!(visited[mat[t][j]] == 1 || mat[t][j] == p[t]) ){
                                cc[t]++;
                            }
                        }
                    }*/
                    visited[t] = 1;
                    q.push(t);
                }
            }
            /*
            for(i=1;i<=n;i++){

                cout << cc[i] << " ";
            }
            cout << endl << endl;
            */
        }
        sum = 0;

            for(i=1;i<=n;i++){

                //cout << cc[i] << " ";
                sum = sum + (n-1-cc[i]);
            }
            //cout << endl;

            cout << "Case "<< caseCounter++ << ": " << n-1 << " " << sum/2 << endl;

        //cout << sum << endl;
    }
    return 0;
}
