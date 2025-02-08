#include<bits/stdc++.h>
using namespace std;

// adjacency list
// adjacency matrix
#define MX 1000

int mat[MX][MX];
int bfsAdjacencyMatrix(){
    queue<int> q;
    q.push(0);
    int minDist = INT_MAX;
    int minV = 0;
    vector<int> visited(MX+4, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=u+1;i<MX;i++){
            if(mat[u][i] > 0 && !visited[i]){
                if(minDist < mat[u][i]){
                    minDist = mat[u][i];
                    minV = i;
                }
                q.push(i);
            }
        }
    }

    return minDist;
}

int bdfAdjacencyList(vector<vector<int>> adj){
    queue<int> q;
    q.push(0);
    int minDist = INT_MAX;
    int minV = 0;
    vector<int> visited(MX+4, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                if(minDist < adj[u][v]){
                    minDist = adj[u][v];
                    minV = v;
                }
                q.push(v);
            }
        }
    }
}

void setupMatrix(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            mat[i][j] = 0;
        }
    }
}

int main(){

    setupMatrix();
    cout << bfsAdjacencyMatrix() << endl;
    return 0;
}
