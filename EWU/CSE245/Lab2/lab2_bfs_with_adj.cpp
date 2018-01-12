#include<bits/stdc++.h>
using namespace std;
list<int> adj[1000];
list<int>::iterator it;
int color[1000], prev[1000], cost[1000];
int nodes;

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
    prev[s] = -1;
    cost[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        u =Q.front();
        Q.pop();
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(color[*it] == 0){
                cost[*it] = cost[u] +1;
                prev[*it] = u;
                color[*it] = 1;
                //cout << "HI " << *it<<endl;
                Q.push(*it);
            }
        }
        color[u] = 2;
    }
}
int main(){
    int k=1,i ,j,a,b,s;
    cout << "Enter Number of nodes: ";
    cin >>nodes;

    while(1){
        cout << "Enter edge number " << k << ": ";
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        if(a > 0 && b >0 && a <=nodes && b <=nodes){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }else{
            cout << "Invalid Input." << endl;
            continue;
        }
        k++;
    }

    for(i=1;i<=nodes;i++){
        printf("Adj[%d]", i);

        for(it=adj[i].begin();it!=adj[i].end();it++){
            printf("->%d", *it);
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
