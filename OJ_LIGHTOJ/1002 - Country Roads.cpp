#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 504
#define inf 50000
int mat[MX][MX];
int visited[MX];
int nmax[MX][MX];

int main(){
    int tc,i,j,u,v,w,k,n,m,caseCounter=1;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = 0;
                nmax[i][j] = inf;
            }
            mat[i][i] = 0;
            nmax[i][i] = 0;
            visited[i] = 0;
        }

        for(i=1;i<=m;i++){
            cin >> u >> v >> w;
            if(20000-w > mat[u][v]){
                mat[u][v] = 20000-w;
                mat[v][u] = 20000-w;
            }
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                if(mat[i][j] == 20000){
                    mat[i][j] = inf;
                }
            }
            mat[i][i] = 0;
            //nmax[i][i] = 0;
            //visited[i] = 0;
        }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%2d ", mat[i][j]);
            //cout << mat[i][j] << " ";
        }
        cout << endl;
    }


        cin >> u;
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(mat[i][j]> mat[i][k] + mat[k][j]){
                        mat[i][j] = mat[i][k] + mat[k][j];
                       // msg(mat[i][k], mat[k][j])
                    }
                }
            }
        }
        cout << "Case "<< caseCounter++ << ": " << endl;
        for(i=0;i<n;i++){
            if(i==u){
                cout << 0 << endl;
            }else if(nmax[i][u] >= inf){
                cout << "Impossible" << endl;
            }else{
                cout << nmax[i][u] << endl;
            }
        }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%2d ", mat[i][j]);
            //cout << mat[i][j] << " ";
        }
        cout << endl;
    }







    }

    return 0;
}
