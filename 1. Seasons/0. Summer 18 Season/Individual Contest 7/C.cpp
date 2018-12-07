#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

#define MX 1004

int dir = 8;
int dx[] = {2, 2, -2,-2, 1,-1,1,-1};
int dy[] = {1,-1,1,-1,2,2,-2,-2};
int mat[MX][MX];
pair<int,pair<int,int> > mp(int a,int b, int c){
    return (make_pair(a, make_pair(b,c)));
}
int main(){

    int i,j,x,y,cost,xx,yy,n;


    for(i=0;i<MX;i++){
        for(j=0;j<MX;j++){
            mat[i][j] = -1;
        }
    }
    queue<pair<int,pair<int,int> > >q;
    q.push(mp(1,1,0));
    mat[1][1] = 0;
    pair<int,pair<int,int> > f;
    while(!q.empty()){
        f = q.front();
        x = f.first;
        y = f.second.first;
        cost = f.second.second;
        //msg2(x,y,cost)
        q.pop();
        for(i=0;i<dir;i++){
            xx = x + dx[i];
            yy = y + dy[i];
            //msg(xx,yy)
            if( !(xx<0 || xx>1000 || yy <0 || yy>1000) ){
                if(mat[xx][yy]== -1){
                    q.push(mp(xx,yy,cost+1));
                    mat[xx][yy] = cost+1;
                }
            }
        }
    }
    //cc("HI")

    cin >> n;
    while(n--){
        cin >> x >> y;
        cout << mat[x][y] << endl;
    }

    return 0;
}
