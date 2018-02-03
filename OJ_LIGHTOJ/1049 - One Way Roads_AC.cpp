#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int mat[104][104];


int main(){
    int tc,n,i,j,a,b,c,sum,u,sum2,s,l,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        int visited[n+2];
        // clearing the mat array

        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = -1;
            }
        }
        for(i=0;i<n;i++){
            cin >> a >> b >> c;
            mat[a][b] = 0;
            mat[b][a] = c;
        }
        queue<int> q;
        for(i=1;i<=n;i++){
            visited[i] = 0;
        }
        /*
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        */



        q.push(1);
        visited[1] = 1;
        sum =0;
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(i=1;i<=n;i++){
                if(mat[u][i] > -1 && visited[i] == 0){
                    q.push(i);
                    sum += mat[u][i];
                    visited[i] = 1;
                     l = i;
                    //check(sum)
                    //msg("HI1", i)
                    break;
                }
            }
        }
        sum += mat[l][1];


        for(i=1;i<=n;i++){
            visited[i] = 0;
        }
        q.push(1);
        sum2 =0;
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(i=n;i>=0;i--){
                if(mat[u][i] > -1 && visited[i] == 0){
                    q.push(i);
                    sum2 += mat[u][i];
                    visited[i] = 1;
                    l = i;
                    //msg("HI2", i)
                    break;
                }
            }
        }
        //msg(l, i)
        //sum2 += mat[1][l];
        //msg(sum , sum2)
        cout << "Case " << caseCounter++ << ": "<< min(sum, sum2) << endl;

    }

    return 0;
}
