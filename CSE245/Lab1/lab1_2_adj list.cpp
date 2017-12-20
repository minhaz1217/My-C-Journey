#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> adj[100];
    list<int>::iterator it;
    int n,k=1,i ,j,a,b;
    cout << "Enter Number of nodes: ";
    cin >>n;

    while(1){
        cout << "Enter edge number " << k << ": ";
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        if(a > 0 && b >0 && a <=n && b <=n){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }else{
            cout << "Invalid Input." << endl;
            continue;
        }
        k++;
    }

    for(i=1;i<=n;i++){
        printf("Adj[%d]", i);

        for(it=adj[i].begin();it!=adj[i].end();it++){
            printf("->%d", *it);
        }
        cout << endl;
    }

    return 0;
}
