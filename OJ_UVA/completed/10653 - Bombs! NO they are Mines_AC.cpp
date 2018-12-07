#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int dir = 4;
int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};

int main(){

    int r,c,rr,bombs,cpos,qq,i,j, sx, sy, ddx,ddy,x,y,w,cost,xx,yy;
    pair<int, pair<int, int> >f;
    while(1){
        scanf("%d%d", &r, &c);
        queue<pair<int, pair<int,int> > >q;
        if(r == 0 && c == 0){
            break;
        }
        int mat[r][c];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                mat[i][j] = 0;
            }
        }
        //cin >> q;
        scanf("%d", &qq);
        while(qq--){
            scanf("%d%d", &rr, &bombs);
            //cin >> rr >> bombs;
            for(i=0;i<bombs;i++){
                scanf("%d", &cpos);
                //cin >> cpos;
                mat[rr][cpos] = 1;
            }
        }
/*
for(int pq=0;pq<r;pq++){
for(int PQ=0;PQ<c;PQ++){
printf("%2d ", mat[pq][PQ]);
//cout << mat[i][j] << " ";
}
cout << endl;
}
*/
    scanf("%d%d%d%d", &sx, &sy , &ddx, &ddy);
    q.push(make_pair(sx,make_pair(sy, 0)));
    mat[sx][sy] = 1;
    while(!q.empty()){
        f = q.front();
        x = f.first;
        y = f.second.first;
        w = f.second.second;
        if(x == ddx && y==ddy){
            cost = w;
            break;
        }
        q.pop();
        for(i=0;i<dir;i++){
            xx = x + dx[i];
            yy = y + dy[i];
            if(!(xx < 0 || xx >= r || yy <0 || yy>=c)){
                if(mat[xx][yy] == 0){
                    q.push(make_pair(xx, make_pair(yy, w+1)));
                    mat[xx][yy] = 1;
                }
            }
        }
    }
    cout << cost << endl;

    }


    return 0;
}
