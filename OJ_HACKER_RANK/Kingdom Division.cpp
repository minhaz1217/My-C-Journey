#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define MX 100005
vector<int>p, adj[MX],visited;
int DP[MX][2][3];
int dp(int u, int color, int safe){
    //msg2(u,color,safe)
    int v,l1,l2;
    if(DP[u][color][safe] != -1){
        return DP[u][color][safe];
    }
    int counter = 0;
    for(int i=0;i<adj[u].size();i++){
        v = adj[u][i];
        if(safe == 1){

            l1 = dp(v,0, color == 0);
            l2 = dp(v,1, color==1);
            DP[u][color][safe] = (l1*l2);
            //return DP[u][color][safe];
        }else{
            l1 = dp(v,0, color == 0);
            l2 = dp(v,1,color==1);
            DP[u][color][safe] = (l1*l2) - l1;
            //return DP[u][color][safe];
        }
        counter++;

    }


    return counter;

}

int main(){
    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    for(int i=0;i<MX;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                DP[i][j][k] = -1;
            }
        }

    }
    /*
    p.assign(n+1, -1);
    visited.assign(n+1,0);
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            v = adj[u][i];
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    */
    int l1, l2;
    l1 = dp(1,1,0);
    l2 = dp(1,0,0);
    cout << l1 * l2 << endl;
    return 0;
}
