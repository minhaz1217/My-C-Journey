#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << "  : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;

#define MX 10
int visited[MX][MX];
int dir = 8;
int ddx[] = {2,2,-2,-2,1,-1,1,-1};
int ddy[] = {1,-1,1,-1,2,2,-2,-2};

int main(){
    int tc,sx,sy,dx,dy,i,j,cost,u,v,uu,vv,w;
    string str1,str2;
    cin >> tc;
    while(tc--){
        cin >> str1 >> str2;
        queue<pair< int, pair<int,int> > >q;
        sx = str1[0] - 'a' + 1;
        sy = str1[1] - '0' ;
        dx = str2[0] -'a'+ 1;
        dy = str2[1] -'0';
        //msg(sx, sy)
        //msg(dx, dy)

    for(i=0;i<MX;i++){
        for(j=0;j<MX;j++){
            visited[i][j] = 0;
        }
    }
    cost = INT_MAX;
    q.push(make_pair(sx,make_pair(sy,0)));
    visited[sx][sy] = 1;
    while(!q.empty()){
        u = q.front().first;
        v = q.front().second.first;
        w = q.front().second.second;
        //msg2(u,v,w)
        q.pop();
        if(u == dx && v == dy){
            cost = min(cost, w);
        }
        for(i=0;i<dir;i++){
            uu = u + ddx[i];
            vv = v + ddy[i];
            if(!(uu <= 0 || uu> 8|| vv <=0 || vv>8)){
                if(!visited[uu][vv]){
                    q.push(make_pair(uu,make_pair(vv,w+1)));
                    visited[uu][vv] = 1;
                }
            }
        }
    }

        cout << cost << endl;
    }

    return 0;
}
