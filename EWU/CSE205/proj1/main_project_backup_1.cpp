#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
const int nodes = 10;
vector<int> graph[nodes];
int gcost[nodes][nodes],big,d1,d2,i,j,randCost=0;
vector<int> selected[1000][2];
int totalCost = 0,prev,selectedCounter= 0,cost = 0;
void addEdge(int a, int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
    randCost = rand()%10 + 6;
    gcost[a][b] = randCost;
    gcost[b][a] = randCost;
}
void initialize(){

    srand(time(NULL));
    for(i=0; i<nodes; i++){
        for(j=0; j<nodes; j++){
            gcost[i][j] = 0;
        }
    }
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(0, 5);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(2, 7);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(3, 6);
    addEdge(3, 8);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(4, 8);
    addEdge(4, 9);
    addEdge(5, 8);
    addEdge(6, 8);
    addEdge(6, 9);
    addEdge(7, 9);
}

void backtrackingToFindValidPaths(int u, int d, bool visited[],int path[], int &path_index){
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d){
        if(path_index == nodes){
            prev = path[0];
            for (int i = 0; i<path_index; i++){
                selected[selectedCounter][0].push_back(path[i]);
                if(i!=0){
                    totalCost += gcost[prev][path[i]];
                    prev =path[i];
                }
            }
            selected[selectedCounter][1].push_back(totalCost);
            totalCost = 0;
            selectedCounter++;
        }
    }
    else{
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); ++it)
            if (!visited[*it]){
                backtrackingToFindValidPaths(*it, d, visited, path, path_index);
            }
    }
    path_index--;
    visited[u] = false;
}
void findPathFromSourceToDest(int s, int d){
    bool *visited = new bool[nodes];
    int *path = new int[nodes];
    int path_index = 0;
    for (int i = 0; i < nodes; i++){
        visited[i] = false;
    }
    backtrackingToFindValidPaths(s, d, visited, path, path_index);
}
int main(){
    int s=0,d,small,finalPathIndex,i,j,k,flag;

    initialize();

    cout << "Adjacency Matrix" << endl << "-------------------" << endl;
    for(i=0; i<nodes; i++){
        for(j=0; j<nodes; j++){
            flag = 0;
            printf("%3d", gcost[i][j]);
            //cout << gcost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    printf("Enter Source Node(%d - %d): ", 0,nodes-1);
    cin >> s;
    for(i=0; i<nodes; i++){
        if(i!= s){
            findPathFromSourceToDest(s,i);
        }
    }

    small = selected[0][1][0];
    finalPathIndex = 0;
    for(i=0; i<selectedCounter; i++){
        if(selected[i][1][0] < small){
            small = selected[i][1][0];
            finalPathIndex = i;
        }
    }
    cout << endl << endl;
    cout << "The shortest the salesperson should travel: \n" ;
    cout << selected[finalPathIndex][0][0];
    for(i=1; i<nodes; i++){
        cout << " > " << selected[finalPathIndex][0][i];
    }
    cout << endl;
    cout << "Cost: " << selected[finalPathIndex][1][0];
    cout << endl;
    return 0;
}
