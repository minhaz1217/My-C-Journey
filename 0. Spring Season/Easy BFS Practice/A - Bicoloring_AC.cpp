#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 204
int visited[MX], colors[MX], p[MX];
int main(){
    int i,u,v,n,BP,j,k,edge;
    while(1){
        cin >> n;
        if(n==0){
            break;
        }
        cin >> edge;
        //msg(n,edge)
        queue<int> q;
        vector<int>mat[n];
        int colors[n];
        for(i=0;i<n;i++){
            visited[i] = 0;
            colors[i] = 0;
            p[i] = i;
        }
        for(i=0;i<edge;i++){
            cin >> u >> v;
            //msg(u,v)
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        q.push(u);
        visited[u] = 1;
        colors[u] = 1;
        BP = 1;
        while(!q.empty() && BP){
            u = q.front();
            q.pop();
            for(i=0;i<mat[u].size();i++){
                v = mat[u][i];
                if(colors[v] == colors[u]){
                    BP = 0;
                    break;
                }
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                    p[v] = u;
                    if(colors[u] == 1){
                        colors[v] = 2;
                    }else{
                        colors[v] = 1;
                    }
                }
            }
        }
        if(BP == 1){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }


    }
    return 0;
}
