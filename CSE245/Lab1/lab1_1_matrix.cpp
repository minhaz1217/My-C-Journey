#include<bits/stdc++.h>
using namespace std;
int main(){
    int mat[100][100];
    int n,k=1,i ,j,a,b;
    cout << "Enter Number of nodes: ";
    cin >>n;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            mat[i][j] = 0;
        }
    }


    while(1){
        cout << "Enter edge number " << k << ": ";
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        if(a > 0 && b >0 && a <=n && b <=n){
            mat[a][b] = 1;
            mat[b][a] = 1;
        }else{
            cout << "Invalid Input." << endl;
            continue;
        }
        k++;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
