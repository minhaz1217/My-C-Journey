//DFS with matrix

#include<iostream>
#include<stdio.h>
using namespace std;
#define check(a) cout << a << endl;
#define MX 1000

int color[MX], prev[MX], time, discover[MX], finish[MX];
int mat[MX][MX];
int nodes, treeEdge = 0, backEdge = 0, crossEdge = 0;

void DFS_visit(int u){
    //check("hi")
    int i;
    color[u] = 1;
    time = time+1;
    discover[u] = time;
    for(i=1;i<=nodes;i++){
        if(mat[u][i] == 1 && color[i]== 0){
            prev[i] = u;
            DFS_visit(i);
        }
    }
    color[u] = 2;
    time = time+1;
    finish[u] = time;
}

void findTypesOfEdges(){
    int i,j;
    for(i=1;i<=nodes;i++){
        for(j=1;j<=nodes;j++){
            if(mat[i][j] == 1){
                if(discover[i] < discover[j] && discover[j] < finish[j] && finish[j] < finish[i]){
                    treeEdge++;
                    cout << i << " --> " << j << " is a TREE edge" << endl;
                }else if(discover[j] < discover[i] && discover[i] < finish[i] && finish[i] < finish[j]){
                    backEdge++;
                    cout << i << " --> " << j << " is a BACK edge" << endl;
                }else if(discover[i] > discover[j]){
                    crossEdge++;
                    cout << i << " --> " << j << " is a CROSS edge" << endl;
                }else if(discover[i] < discover[j]){
                    crossEdge++;
                    cout << i << " --> " << j << " is a CROSS edge" << endl;

                }
            }
        }
    }


}

void DFS(){
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
            //mat[b][a] = 1;
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
    /*
    cout << "Enter source node: " << endl;
    cin >> s;
    if(s<=0 || s>nodes){
        cout << "Invalid Source" << endl;
    }else{
        DFS(s);
    }
    */
    DFS();
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
    findTypesOfEdges();

    cout << "Tree Edge: " << treeEdge << endl;
    cout << "Back Edge: " << backEdge << endl;
    cout << "Cross Edge: " << crossEdge << endl;
    return 0;
}



