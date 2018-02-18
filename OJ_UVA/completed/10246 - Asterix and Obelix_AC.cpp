#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 90
long long mat[MX][MX],cost[MX];
long long cc[MX][MX];
long long improved;
long long warshal(long long n){
    long long i,j,k,myC;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                //if(mat[i][j] > 0 && mat[i][k]>0 && mat[k][j] > 0){

                    //myC = max(cost[i], max(cost[j] , max(cc[i][j], max(cost[k], max(cc[i][k], cc[k][j])))));
                    myC = max(cc[i][k], cc[k][j]);
                    if(mat[i][j]+cc[i][j]> mat[i][k] + mat[k][j] + myC){
                        mat[i][j] = mat[i][k] + mat[k][j];
                        cc[i][j] = myC;
                        improved= 1;
                        //msg(k,myC)
                    }
                //}
            }
        }
    }
}


int main(){
    long long n,r,q,a,b,i,j,c,caseCounter = 1;
    while(1){
        cin >> n >> r >> q;
        if(n==0 && r == 0 && q == 0){
            break;
        }
        if(caseCounter>1){
            cout << endl;
        }
        cout << "Case #" << caseCounter++ << endl;
        for(i=0;i<MX;i++){
            for(j=0;j<MX;j++){
                mat[i][j] = 500000;
                cc[i][j] = 0;
            }
            cost[i] = 0;
        }
        for(i=1;i<=n;i++){
            cin >> cost[i];
            cc[i][i] = cost[i];
        }

        for(i=1;i<=r;i++){
            cin >> a >> b >> c;
            mat[a][b] = c;
            mat[b][a] = c;
            cc[a][b] = max(cost[a],cost[b]);
            cc[b][a] = max(cost[a],cost[b]);
        }

        c = 1;
        warshal(n);
        while(c<=n && improved){
            improved = 0;
            c++;
            warshal(n);
        }

        for(i=1;i<=q;i++){
            cin >> a >> b;
            if( mat[a][b] + cc[a][b] >= 500000){
                cout << -1 << endl;
            }else{
                //msg(mat[a][b], cc[a][b])
        //cout << c << endl;
                cout <<  mat[a][b] + cc[a][b] << endl;
            }
            //cout << mat[a][b] + cc[a][b] << endl;
        }

    }
    return 0;
}
