#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,m,s,i,u,v,a,b,counter=0;

    cin >> n >> m >> s;
    int visited[n+1];
    vector<int>mat[n+1];
    for(i=0;i<=n;i++){
        visited[i] = 0;
    }
    while(m--){
        cin >> a >> b;
        mat[a].push_back(b);
    }
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    counter = 1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(i=0;i<mat[u].size();i++){
            v = mat[u][i];
            if(!visited[v]){
                q.push(v);
                visited[v]  =1;
                counter++;
            }
        }
    }
    cout << n - counter << endl;


    return 0;
}
