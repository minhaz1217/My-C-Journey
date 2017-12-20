//DFS with matrix

#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 1000

int color[MX], prev[MX], t, discover[MX], finish[MX];
list<int> adj[MX];
list<int>::iterator it;
int nodes;

void DFS_visit(int u){
    int i;
    color[u] = 1;
    t = t+1;
    discover[u] = t;
    int k;
    if(!adj[u].empty()){
    for(it=adj[u].begin();it != adj[u].end(); it++){
            k = *it;
            /*
            if(k>nodes){
                break;
            }
            */
            if(color[k]== 0){
                prev[k] = u;
                //cout << k << endl;
                if(adj[k].size() == 0){
                    msg("Size: " , k)
                    color[k] = 2;
                    t = t+1;
                    finish[k] = t;
                }else{
                    DFS_visit(k);
                }
            }
    }
    color[u] = 2;
    t = t+1;
    finish[u] = t;
    }else{
    color[u] = 2;
    t = t+1;
    finish[u] = t;
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
    t = 0;

    for(i=1;i<=nodes;i++){
        //for(it = adj[i].begin();it!=adj[i].end();it++){
            if(color[i] == 0){
                //cout << "HELLO" <<endl;
                if(adj[i].empty()){
                    msg("LOG1" , i)
                    discover[i] = t++;
                    color[i] = 2;
                    t = t+1;
                    finish[i] = t;
                }else{
                    DFS_visit(i);
                }
            }
        //}
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
            //adj[b].push_back(a);
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




    /*
    cout << "Enter source node: " << endl;
    cin >> s;
    if(s<=0 || s>nodes){
        cout << "Invalid Source" << endl;
    }else{
        DFS(s);
    }
    */




    cout << "Sizes: " << endl;
    for(i=1;i<=nodes;i++){
        cout << adj[i].size() << " " ;
    }
    cout << endl;



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

    return 0;
}



