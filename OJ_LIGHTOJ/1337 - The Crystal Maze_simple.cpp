#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 504
int dir = 4;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char mat[MX][MX];
int visited[MX][MX];

int main(){
    int i,j,n,m,q,x,y,u,v,uu,vv,mark,counter,tc,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n >> m >> q;
        for(i=0;i<n;i++){
                for(j=0;j<m;j++)
            visited[i][j] = 0;
        }
        for(i=0;i<n;i++){
            scanf("%s", &mat[i]);
        }
        cout << "Case "<< caseCounter++ << ":" << endl;

        mark = 0;
        while(q--){
            queue<pair<int, int> >q;
            //cin >> x >> y;
            scanf("%d%d",&x, &y);
            x--;
            y--;
            mark++;
            counter = 0;
            q.push(make_pair(x,y));
            visited[x][y] = mark;
            while(!q.empty()){
                u = q.front().first;
                v = q.front().second;
                //msg(u,v)
                q.pop();
                if(mat[u][v] == 'C'){
                    //msg(u,v)
                    counter++;
                }
                for(i=0;i<dir;i++){
                    uu = u+dx[i];
                    vv = v+dy[i];
                    if( !(uu<0 || uu>=n || vv<0 || vv >=m)){
                        if(visited[uu][vv]!= mark && mat[uu][vv] != '#'){
                            q.push(make_pair(uu,vv));
                            visited[uu][vv] = mark;
                        }
                    }
                }

            }
            printf("%d\n", counter);
            //cout << counter << endl;
        }
    }
    return 0;
}
