#include<iostream>
#include<stdio.h>
using namespace std;
#define check(a) cout << a << endl;
#define MX 1000

int color[MX], prev[MX], time, discover[MX], finish[MX];
int mat[MX][MX], low[MX];
int nodes;

void DFS_visit(int u){
    //check("hi")
    int i;
    color[u] = 1;
    time = time+1;
    discover[u] = time;
    low[u] = discover[u];
    for(i=1;i<=nodes;i++){
        if(mat[u][i] == 1 && color[i]== 0){
            prev[i] = u;
            DFS_visit(i);
            if(low[i] >= discover[u]){
                cout << i << " is an articulation point." << endl;
            }
            if(low[i] < low[u]){
                low[u] = low[i];
            }
        if(prev[i] != u){
            if(discover[i] < low[u]){
                low[i] = discover[u];
            }
        }
        }


    }
    color[u] = 2;
    //time = time+1;
    //finish[u] = time;
}



void DFS(int s){
    /*
     0 = white
     1 = gray
     2 = black
    */
    int i,u;
    for(i=1;i<=nodes;i++){
        color[i] = 0;
        prev[i] = -1;
        finish[i] = 0;
        low[i] = -1;
        discover[i] = 0;
        //cost[i] = 20000000;
    }
    time = 0;

    for(i=1;i<=nodes;i++){
        if(color[i] == 0){
            DFS_visit(i);
        }
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
        DFS(s);
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
    cout << "P: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",prev[i]);
    }
    cout << endl;
    cout << "D: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",discover[i]);
    }
    cout << endl;
    cout << "F: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",finish[i]);
    }
    cout << endl;
    cout << "L: ";
    for(i=1;i<=nodes;i++){
        printf("%2d",low[i]);
    }
    cout << endl;
    return 0;
}



