#include<bits/stdc++.h>
using namespace std;

// adjacency list
// adjacency matrix
#define MX 1000

int mat[MX][MX];
vector<bool> visited(MX, 0);
vector<vector<int>> adj;

int dfsMatrix(int u){
    for(int v=u;v<MX;v++){
        if(mat[u][v] == 1 && !visited[v]){
            visited[v] = true;
            dfsMatrix(v);
            visited[v] = false;
        }
    }
}

int dfsAdj(int u){
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!visited[v]){
            visited[v] = true;
            dfsAdj(v);
            visited[v] = false;
        }
    }
}
int dfsAdjacencyMatrix(){
    dfsAdj(0);
}

int dfsAdjacencyList(vector<vector<int>> adj){
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
    cout << dfsAdjacencyMatrix() << endl;
    return 0;
}
