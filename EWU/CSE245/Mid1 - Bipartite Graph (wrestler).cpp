#include<bits/stdc++.h>
using namespace std;
int color[1000], prev[1000], cost[1000];
int mat[1000][1000];
int nodes;
/*
if cost of a node is 0 or 2 than they are on set A
    if cost is 1 than they are on set B
if cost of more than 2 than the graph is not bipartite

*/



void BFS(int s){
    /*
     0 = white
     1 = gray
     2 = black
    */
    queue<int> Q;
    int i,u;
    for(i=1;i<=nodes;i++){
        color[i] = 0;
        prev[i] = -1;
        cost[i] = 20000000;
    }
    color[s] = 1;
    cost[s] = 0;
    cout << s << " is babyface." << endl;
    Q.push(s);
    while(!Q.empty()){
        u =Q.front();
        Q.pop();
        for(i=1;i<=nodes;i++){
            if(mat[u][i] == 1 && color[i] == 0){
                //cout << "Inserting " << i  << " from " << u << endl;
                cost[i] = cost[u] +1;
                if(cost[i] == 0 || cost[i] == 2){
                    cout << i << " is babyface." << endl;
                }else if(cost[i]==1){
                    cout << i << " is heels." << endl;
                }
                color[i] = 1;
                prev[i] = u;
                Q.push(i);
            }
        }
        color[u] = 2;
    }
}

int main(){
    int k=1,i ,j,a,b,s;
    cout << "Enter Number of nodes: ";
    cin >>nodes;
    for(i=1;i<=nodes;i++){
        for(j=1;j<=nodes;j++){
            mat[i][j] = 0;
        }
    }


    while(1){
        cout << "Enter edge number " << k << ": ";
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        if(a > 0 && b >0 && a <=nodes && b <=nodes){
            mat[a][b] = 1;
            mat[b][a] = 1;
        }else{
            cout << "Invalid Input." << endl;
            continue;
        }
        k++;
    }
    cout << "Matrix" << endl;
    for(i=1;i<=nodes;i++){
        for(j=1;j<=nodes;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter source node: " << endl;
    cin >> s;
    if(s<=0 || s>nodes){
        cout << "Invalid Source" << endl;
    }else{
        BFS(s);
    }
    cout << "N: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",i);
    }
    cout << endl;
    cout << "C: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",color[i]);
    }
    cout << endl;
    cout << "D: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",cost[i]);
    }
    cout << endl;
    cout << "P: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",prev[i]);
    }
    cout << endl;
    return 0;
}



