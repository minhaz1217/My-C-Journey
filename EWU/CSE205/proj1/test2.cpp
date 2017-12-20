#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
vector<int> graph[5];
int gcost[5][5],big,d1,d2;
vector<int> selected[100][2];
list<int> *adj;
int totalCost = 0,prev;
int selectedCounter= 0, V= 5,cost = 0;
void addEdge(int a, int b){
    graph[a].push_back(b);
    graph[b].push_back(a);
    int randCost = rand()%10 + 1;
    gcost[a][b] = randCost;
    gcost[b][a] = randCost;
    big = randCost;
}



void printAllPathsUtil(int u, int d, bool visited[],int path[], int &path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    if (u == d)
    {
        if(path_index == V){
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
    else
    {
        vector<int>::iterator i;
        for (i = graph[u].begin(); i != graph[u].end(); ++i)
            if (!visited[*i]){
                printAllPathsUtil(*i, d, visited, path, path_index);


            }
    }

    path_index--;
    visited[u] = false;
}
void printAllPaths(int s, int d)
{
    bool *visited = new bool[V];
    int *path = new int[V];
    int path_index = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    printAllPathsUtil(s, d, visited, path, path_index);
}
int main(){
    int s=0,d=4,small,selection;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    int i,j,k,flag;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            flag = 0;
            for(k=0;k<V;k++){
                if(graph[i][j] == k){
                    //cout << k << " ";
                    if(gcost[i][j] > big){
                        big = gcost[i][j];
                        d1 = i;
                        d2 = j;
                    }
                    cout << gcost[i][j] << " ";
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;


    printAllPaths(s,d1);
    printAllPaths(s,d2);

    small = selected[0][1][0];
    for(i=0;i<selectedCounter;i++){
        /*
        for(j=0;j<selected[i][0].size();j++){
            cout << selected[i][0][j] << " ";
        }
        */
        if(selected[i][1][0] < small){
            small = selected[i][1][0];
            selection = i;
        }
        /*
        cout << "  Cost: " << selected[i][1][0];
        cout << endl;
        */
    }
        for(i=0;i<V;i++){
        cout << selected[selection][0][i] << " ";
    }
        cout << endl;
        cout << " Cost: " << selected[selection][1][0];


    cout << endl;
	return 0;
}
