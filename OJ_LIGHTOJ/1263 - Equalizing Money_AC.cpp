#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 1050

int mat[MX][MX];
int arr[MX];
int visited[MX];




int main(){
    int tc,n,m,sum,u,v,counter,i,j,myMath, flag,caseCounter = 1;
    queue<int> q;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        q.empty();
        for(i=0;i<=n;i++){
            visited[i] = 0;
            for(j=0;j<=n;j++){
                mat[i][j] = 0;
            }
        }
        sum = 0;
        for(i=1;i<=n;i++){
            cin >> arr[i];
            sum += arr[i];
        }
        for(i=0;i<m;i++){
            cin >> u >> v;
            mat[u][v] = 1;
            mat[v][u] = 1;
        }

        if(sum%n == 0){
            myMath = sum/n;
            //msg("MYMATH: ", myMath)
            flag= 1;
            for(i=1;i<=n;i++){
                sum = 0;
                counter =0;
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                    while(!q.empty() && flag){
                        u = q.front();
                        sum += arr[u];
                        counter++;
                        q.pop();
                        for(j=1;j<=n;j++){
                            if(!visited[j] && mat[u][j]){
                                q.push(j);
                                visited[j] = 1;
                            }
                        }
                    }
                    //msg(sum%counter , counter * myMath)
                    if(!(sum%counter == 0 && counter*myMath == sum)){
                        //check("HI")
                        flag = 0;
                        break;
                    }
                }
                //check(i)
                //msg(sum, counter)
                //cout << myMath * counter << endl << endl;
            }
        }else{
            flag = 0;
        }
        if(flag == 0){
            cout << "Case "<< caseCounter++ << ": No" << endl;

        }else{
            cout << "Case "<< caseCounter++ << ": Yes" << endl;

        }

    }



    return 0;
}
