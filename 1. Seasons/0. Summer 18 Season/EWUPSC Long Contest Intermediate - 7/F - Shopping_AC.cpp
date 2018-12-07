// weighted bfs

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int dir = 4;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

pair<int,pair<int,int> > mmp(int a, int b, int c){
    return (make_pair(a, make_pair(b,c)));
}
int main(){

    while(1){
        long long int n,m,destx,desty, sourcex, sourcey,x,y,vx,vy,cost,w;

        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }
        char mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'S'){
                    sourcex = i;
                    sourcey = j;
                }
                if(mat[i][j] == 'D'){
                    destx = i;
                    desty = j;
                }
            }
        }
        priority_queue<pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >, greater< pair<int,pair<int,int> > > >q;
        pair<int,pair<int,int> > f;
        q.push(mmp(0,sourcex, sourcey));
        mat[sourcex][sourcey] = 'X';

        cost = INT_MAX;
        while(!q.empty() ){
            f = q.top();
            q.pop();
            /*
 for(int pq=0;pq<n;pq++){
    for(int PQ=0;PQ<m;PQ++){
        printf("%d ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/
            w = f.first;
            x = f.second.first;
            y = f.second.second;

            //msg2(x,y,w)
            if(x == destx && y == desty){
                cost = min(cost, w);
                break;
            }
            for(int i=0;i<dir;i++){
                vx = x + dx[i];
                vy = y + dy[i];
                //msg3("H", vx, vy, mat[vx][vy])
                if( !(vx < 0 || vx>=n || vy <0 || vy>=m) ){
                    if( mat[vx][vy] != 'X' ){
                        if(mat[vx][vy] == 'D'){
                            q.push(mmp(w,vx,vy));
                        }else{
                            q.push(mmp(w+ (mat[vx][vy] -'0'), vx,vy));
                            mat[vx][vy] = 'X';
                        }
                    }
                }
            }


        }


        cout << cost << endl;


    }
    return 0;
}
