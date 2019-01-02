#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define MX 100004

int main(){
    int n,counter,u,a,b,v,found;

    vector<int>vec;
    vector<int>visited;
    cin >> n;
    vector<int>mat[n+1];
    visited.assign(n+4,0);
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        mat[i].push_back(a);
        mat[a].push_back(b);
        mat[i].push_back(b);
        mat[b].push_back(a);
        //mat[i][a] = 1;
        //mat[a][b] = 1;
    }
    /*
    for(int i = 1;i<=n;i++){
        msg("TRREE", i)
        for(int j = 0;j<mat[i].size();j++){
            cout << mat[i][j] << " " ;
        }
        cout << endl;
    }
    */
    u = 1;
    visited[u] = 1;
    counter = 1;
    vec.push_back(u);
    while(counter!= n){
        found = 0;
        for(int i=0;i<mat[u].size();i++){
            v = mat[u][i];
            if(!visited[v]){
                //msg("Visitng", v)
                /*
                for(int i=1;i<=n;i++){
                    msg(i,visited[i])
                }
                */
                for(int j=0;j<mat[v].size();j++){
                    if(mat[v][j] == u){
                        vec.push_back(v);
                        visited[v] = 1;
                        counter++;
                        found = 1;
                        u = v;
                        //msg("SELECTED", v)
                        break;
                    }
                }
                if(found == 1){
                    break;
                }
            }
        }
    }
    for(int i =0;i<n;i++){

        if(i > 0){
            cout << " ";
        }
        cout << vec[i];
    }



    return 0;
}
