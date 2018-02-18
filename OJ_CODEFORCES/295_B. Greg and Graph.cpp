#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 504
#define INF 50000
int mat[MX][MX], weight[MX][MX];

int main(){
    int n,i,j,k,a,sum,l;
    cin >> n;

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            mat[i][j] = INF;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> a;
            mat[i][j] = a;
        }
    }
    for(l=1;l<=n;l++){
        cin >> a;

        sum = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                weight[i][j] = mat[i][j];
            }
        }
for(int pq=0;pq<=n;pq++){
for(int PQ=0;PQ<=n;PQ++){
printf("%2d ", weight[pq][PQ]);
//cout << mat[i][j] << " ";
}
cout << endl;
}


for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(weight[i][j] > weight[i][k] + weight[k][j]){
                msg2("Reducde", weight[i][j], weight[i][k]+weight[k][j])
                cout << "FOR "<< k << " From " << i << " to " << j << endl;
                weight[i][j] = weight[i][k] + weight[k][j];
            }
        }
    }
}
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                    sum += weight[i][j];
            }
        }
        cout << sum <<endl;
for(int pq=0;pq<=n;pq++){
for(int PQ=0;PQ<=n;PQ++){
printf("%2d ", weight[pq][PQ]);
//cout << mat[i][j] << " ";
}
cout << endl;
}


        for(i=1;i<=n;i++){
            weight[a][i] = INF;
            weight[i][a] = INF;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(weight[i][j] > weight[i][k] + weight[k][j]){
                        weight[i][j] = weight[i][k] + weight[k][j];
                    }
                }
            }
        }
    }


    return 0;
}
