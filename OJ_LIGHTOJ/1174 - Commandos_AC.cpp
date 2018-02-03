#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 105
#define INFINITE 50000

int mat[MX][MX];
int visited[MX];
int n,m,s,d;

int main(){
    int tc,a,b,i,j,caseCounter = 1,currBig = INT_MIN,k;
    int p[MX];
    queue<pair<int, int> > q;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        q.empty();
        currBig = INT_MIN;
        for(i=0;i<MX;i++){
            for(j=0;j<MX;j++){
                mat[i][j] = INFINITE;
            }
            visited[i] = 0;
            mat[i][i] = 0;
            p[i] = -1;
        }

        while(m--){
            cin >> a >> b;
            mat[a][b] = 1;
            mat[b][a] = 1;
        }
        cin >> s >> d;


        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(mat[i][j] > mat[i][k] + mat[k][j]){
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }


        q.push(make_pair(s, 0));
        visited[s] = 1;
        while(!q.empty()){
            pair<int, int>u;
            u = q.front();
            q.pop();
            currBig = max(currBig, mat[u.first][d]+u.second);
            for(i=0;i<n;i++){
                if(mat[u.first][i] == 1 && !visited[i] ){
                    pair<int,int> v = make_pair(i, u.second+1);
                    p[i] = u.first;
                    visited[i] = 1;
                    q.push(v);
                    //cout << "Pushed " << i << " From " << p[i] << endl;
                }
            }
        }





        cout << "Case "<< caseCounter++ << ": " << currBig << endl;
    }

    return 0;
}
