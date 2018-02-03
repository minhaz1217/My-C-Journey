//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
/*
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b  << " : " << c << endl;
*/
char mat[1004][1004];
int visited[1004][1004];
int dir = 4;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main(){
    int tc,n,m,i,j,tx,ty,ux,uy,maxx,cc;
    queue<pair<int, int> > qq;
    queue<pair<int, pair<int, int> > >q;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin >> mat[i][j];
                if(mat[i][j] == '.'){
                    qq.push(make_pair(i,j));
                    //msg2("HI", i, j)
                }
            }
        }
        /*
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
*/

        //msg("QQ size", qq.size())
        maxx = -100;
        while(!qq.empty()){
            ux = qq.front().first;
            uy = qq.front().second;
            //msg2("q1", ux, uy)
            qq.pop();
            if(!visited[ux][uy]){
                //cout << "HELLO" << endl;
                q.push(make_pair(ux, make_pair(uy, 0)));
                visited[ux][uy] = 1;
                while(!q.empty()){
                    ux = q.front().first;
                    uy = q.front().second.first;
                    cc = q.front().second.second;
                    q.pop();
                    //msg2(ux,uy,cc)
                    maxx = max(maxx, cc);
                    for(i=0;i<dir;i++){
                        tx = ux + dx[i];
                        ty = uy + dy[i];
                        if(!(tx <0 || ty<0 || tx >=m || ty >=n)){
                        if(!visited[tx][ty] && mat[tx][ty] == '.'){
                            q.push(make_pair(tx, make_pair(ty, cc+1)));
                            visited[tx][ty] = 1;
                        }
                        }
                    }
                }
            }

        }
        cout << "Maximum rope length is " << maxx  << "."<< endl;


    }


    return 0;
}
