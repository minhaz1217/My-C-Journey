#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104

char mat[MX][MX];
int visited[MX][MX];
pair<int, pair<int,int> >mmp(int x, int y, int c){
    return (make_pair(x, make_pair(y,c)));
}
int checkInMid(int a, int b, int p, int q, int x, int y){
    // a < x < p
    int t1,t2,b1,b2;
    t1 = max(a,p);
    t2 = min(a,p);
    b1 = max(b,q);
    b2 = min(b,q);
    if( (x >= t2 && x <= t1) && ( y>=b2 && y<=b1 ) ){
        return 1;
    }
    return 0;
}

int main(){
    int n,i,j,sx,sy,dx,dy,ux,uy,w,cost,foundX,u,v;
    cin >> n;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    cin >> sx >> sy >> dx >> dy;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
    queue<pair<int, pair<int,int> > >q;
    pair<int, pair<int,int> >f;
    q.push(mmp(sx,sy,0));
    visited[sx][sy] = 1;
    int foundPath = 0;
    while(!q.empty()){
        f = q.front();
        ux = f.first;
        uy = f.second.first;
        w = f.second.second;
        //msg2(ux,uy,w)
        q.pop();
        if(ux == dx && uy == dy){
            cost = w;
            break;
        }
        for(i=ux;i<n;i++){
            if(mat[i][uy] == 'X'){
                break;
            }else if(!visited[i][uy]){
                u = i;
                v = uy;
                q.push(mmp(u,v,w+1));
                visited[u][v] = 1;

            }
        }


        for(i=ux;i>=0;i--){
            if(mat[i][uy] == 'X'){
                break;
            }else if(!visited[i][uy]){
                u = i;
                v = uy;
                q.push(mmp(u,v,w+1));
                visited[u][v] = 1;

            }
        }

        for(i=uy;i>=0;i--){
            if(mat[ux][i] == 'X'){
                break;
            }else if(!visited[ux][i]){
                u = ux;
                v = i;
                q.push(mmp(u,v,w+1));
                visited[u][v] = 1;

            }
        }

        for(i=uy;i<n;i++){
            if(mat[ux][i] == 'X'){
                break;
            }else if(!visited[ux][i]){
                u = ux;
                v = i;
                q.push(mmp(u,v,w+1));
                visited[u][v] = 1;
            }
        }
    }
    cout << cost << endl;




    return 0;
}
