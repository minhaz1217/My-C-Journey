#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,u,v,bipartite,i,l;
    while(1){
        cin >> n;
        int  color[n+4],p[n+4];
        vector<int>mat[n+4];
        if(n == 0){
            break;
        }
        while(1){
            cin >> u >> v;
            if(u== 0 && v == 0){
                break;
            }
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
//        visited[u] = 1;
        color[u] = 1;
        for(i=0;i<=n;i++){
            color[i] = 0;
        }
        bipartite = 1;
        while(!q.empty() && bipartite){
            u = q.front();
            q.pop();
            //cc(u)
            for(i=0;i<mat[u].size();i++){
                v = mat[u][i];
                if(color[v] == 0){
                    if(color[u] == 2){
                        color[v] = 1;
                    }else{
                        color[v] = 2;
                    }
                    q.push(v);
                }else if(color[v] == color[u] ){
                    bipartite = 0;
                    break;
                }
            }

        }
        if(bipartite){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
