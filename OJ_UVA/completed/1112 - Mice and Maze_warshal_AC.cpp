#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define inf 50000
#define MX 504
int mat[MX][MX];
int weight[MX][MX];
//int mat[MX][MX];
int main(){
    int tc,n,s,t,m,u,v,w,ww,i,counter,myC = 1,j,k;
    pair<int, int> f;
    cin >> tc;
    while(tc--){
        cin >> n >> s >> t >> m;
        if(myC > 1){
            cout << endl;
        }
        myC++;


        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = inf;
            }
            mat[i][i] = 0;
            //weight[i][i] = 0;
        }

        for(i=1;i<=m;i++){
            cin >> u >> v >> w;
            mat[u][v] = w;
            //mat[u].push_back(make_pair(v,w));
        }

        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(mat[i][j] > mat[i][k] + mat[k][j]){
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }


        counter = 0;
        for(i=1;i<=n;i++){
            if(mat[i][s] <=t){
                counter++;
            }
        }
        cout << counter << endl;


    }

    return 0;
}
