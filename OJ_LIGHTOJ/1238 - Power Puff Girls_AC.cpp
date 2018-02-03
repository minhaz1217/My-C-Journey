#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c ) cout << a << " : " << b << " : " << c << endl;
#define MX 24
char mat[MX][MX];
int dir = 4,m,n,aPos, bPos, cPos;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int bfs(int x, int y){
    int i,xx,yy,z;
    char temp;
    queue<pair<int, pair<int,int> > >q;
    q.push(make_pair(x,make_pair(y,0)));
    while(!q.empty()){
        pair<int, pair<int, int> >u;
        //check(q.size())
        u = q.front();
        x = u.first;
        y = u.second.first;
        z = u.second.second;
        q.pop();
        for(i=0;i<dir;i++){
            xx = x + dx[i];
            yy = y + dy[i];
            //msg(xx, yy)
            if(xx >= 0 && xx<n && yy >=0 && yy<m){
                temp = mat[xx][yy];
                //cc(temp)
                if(temp == '.' || temp == 'h' || temp == 'a' || temp == 'c' || temp == 'b'){
                    //msg2("P", xx, yy)
                    mat[xx][yy] = '#';
                    if(temp == 'a'){
                        aPos = z+1;
                    }else if(temp == 'b'){
                        bPos = z+1;
                    }else if(temp == 'c'){
                        cPos = z+1;
                    }
                    q.push(make_pair(xx, make_pair(yy, z+1)));
                }
            }
        }
    }
}


int main(){

    int tc,i,j,caseCounter = 1,hx,hy;

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'h'){
                    hx = i;
                    hy = j;
                }
            }
        }
        bfs(hx,hy);
        //cout << ax << " " << bx << " " << cx << endl;
        cout << "Case "<< caseCounter++ << ": "<< max(aPos, max(bPos,cPos)) << endl;

    }
    return 0;
}
