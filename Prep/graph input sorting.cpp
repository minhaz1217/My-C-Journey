#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int mat[500][500];
    int i,j,a,b,c,n ;
    while(1){
        cin >> a >> b>> c;
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        mat[min(a,b)][max(a,b)] = c;
        n = max(n,max(a,b));
    }

    cout << endl << endl << endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(mat[i][j] >0){
                cout << i << " " << j << " " << mat[i][j] << endl;
            }
        }
    }


    return 0;
}
