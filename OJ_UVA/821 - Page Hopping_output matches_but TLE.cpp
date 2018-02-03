#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 104
#define INF 50000
int mat[MX][MX];


int main(){
    int u,v,nodes = 0,i,j,k,sum,counter,caseCounter = 1;
    while(1){
        scanf("%d %d", &u, &v);
        //cin >> u >> v;
        if(u == 0 && v ==0){
            break;
        }
        nodes = 0;
            for(i=0;i<MX;i++){
                for(j=0;j<MX;j++){
                    mat[i][j] = INF;
                }
                mat[i][i] = 0;
            }
       //msg(u,v)
        mat[u][v] = 1;
        nodes= max(nodes, max(u,v));
        while(1){

        scanf("%d %d", &u, &v);
            //cin >> u >> v;
            //msg(u,v)
            if(u == 0 && v ==0){
                break;
            }
            mat[u][v] = 1;
            nodes= max(nodes, max(u,v));

            for(k=1;k<=nodes;k++){
                for(i=1;i<=nodes;i++){
                    for(j=1;j<=nodes;j++){
                        if(mat[i][j] > mat[i][k] + mat[k][j]){
                            mat[i][j] = mat[i][k] + mat[k][j];
                        }
                    }
                }
            }
        }
            sum = 0;
            counter = 0;


/*
    for(int pp =0;pp<=nodes;pp++){
        for(int qq=0;qq<=nodes;qq++){
            printf("%2d ", mat[pp][qq]);
            //cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    */
            for(i=1;i<=nodes;i++){
                for(j=1;j<=nodes;j++){
                    if(mat[i][j] < INF){
                        sum += mat[i][j];
                        counter++;
                    }
                }
            }
            counter -= nodes;
            printf("Case %d: average length between pages = %.3lf clicks\n", caseCounter++, (double)((double)sum/(counter)));
            //msg(sum, counter)
            //check((double)sum/(double)counter)


    }

    return 0;
}
