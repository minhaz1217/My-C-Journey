#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int nodes, edges, g[MAX][MAX];
stack<int> st;
queue<int> q;
void createGraph(){
    int i,j,a,b;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            g[i][j]= 0;
        }
    }

    cout << "Enter Number of Nodes: " << endl;
    cin >> nodes;
    edges = nodes * (nodes-1);
    for(i=0;i<=edges;i++){
        cout <<"Enter Edges(a, b): " << endl;
        cin >> a >> b ;
        if(a < 0 || b < 0){
            break;
        }
        g[a][b] = 1;
        g[b][a] = 1;
    }
}
void displayGraph(){
    int i,j;
    cout << "   ";
    for(i=1;i<10;i++){
        cout << i << " ";
    }
    cout << "\n----------------------------------\n";
    for(i=1;i<10;i++){
        cout << i << ": ";
        for(j=1;j<10;j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
void addVertexAndEdges(){
    int newVertex,newEdge, a,b,i;
    cout << "How many new Vertex?: ";
    cin >> newVertex;
    nodes += newVertex;
    for(i=0;i<2*nodes;i++){
        cout << "Enter edge(a,b): " << endl;
        cin >> a >> b;
        if(a < 0 || b < 0){
            break;
        }
        g[a][b] = 1;
        g[b][a] = 1;
    }
}
void deleteVertex(){
    int a,i,j;
    printf("Which node do you want to delete? (0-%d): ", nodes);
    cin >> a;
    cout <<"HI" << a << endl;
    for(i = 0;i<nodes;i++){
        g[i][a] = 0;
        g[a][i] = 0;
    }
    cout << "After" << endl;
    displayGraph();

    for(i=a;i<nodes+1;i++){
        for(j=1;j<nodes+1;j++){
/*
            g[i][j] = g[i+1][j];
            g[j][i] = g[j][i+1];
*/
            g[i][j] = g[i+1][j];
            g[j][i] = g[j][i+1];
            if(i==j){
                g[i][j] = 0;
            }
        }
    }

    nodes--;
}

void DFT(){
    int visited[10000] = {0},work,i,j, working[1000] = {0};
    visited[0]= 1;
    st.push(1);
    cout << "DFT: " << endl;
    while(st.size() != 0){
        work = st.top();
        st.pop();
        cout << work  << " ";
        visited[work] = 1;
        working[work] = 1;
        for(j=1;j<=nodes;j++){
            if(g[work][j] && !visited[j]){
                if(!working[j]){
                    st.push(j);
                    working[j] = 1;
                }
            }
        }
    }
    cout << endl;


}

void BFT(){
    int visited[10000] = {0},work,i,j,working[1000] ={0};
    visited[0]= 1;
    q.push(1);
    cout << "BFT: " << endl;

    while(q.size() != 0){

        work = q.front();
        q.pop();
        cout << work  << " ";
        visited[work] = 1;
        working[work] = 1;
        for(j=1;j<=nodes;j++){
            if(g[work][j] && !visited[j]){
                if(!working[j]){
                    q.push(j);
                    working[j] = 1;
                }
            }
        }
    }
    cout << endl;


}
int main(){
    createGraph();
    displayGraph();
    //deleteVertex();
    //displayGraph();
    DFT();
    BFT();


    return 0;
}
