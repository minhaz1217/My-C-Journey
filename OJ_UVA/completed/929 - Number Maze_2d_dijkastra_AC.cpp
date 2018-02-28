#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1004
#define INF 500000
int weight[MX+1][MX+1];
int visited[MX+1][MX+1];
//int weight[MX+2];
pair<int, pair<int,int> > mmp(int x,int y, int w){
    return make_pair(x, make_pair(y,w));
}
int dir = 4;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main(){
    int tc,i,j,n,m,a,w,nod,u,v,s,ww,u1,u2,v1,v2;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        int mat[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> mat[i][j];
                weight[i][j] = INF;
                visited[i][j] = 0;
            }
        }
/*
        for(i=0;i<m*n;i++){
            cout << i << "-> ";
            for(j=0;j<mat[i].size();j++){
                cout << mat[i][j].second << ", ";
            }
        cout << endl;
        }
        */

        priority_queue< pair<int, pair<int,int> > , vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > >pq;
        pq.push( mmp(mat[0][0],0,0));

/*
for(int pq=0;pq<n;pq++){
    for(int PQ=0;PQ<m;PQ++){
        printf("%2d ", weight[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/

        //weight[s] = 0;
        weight[0][0] = mat[0][0];
        while(!pq.empty()){
            u1 = pq.top().second.first;
            u2 = pq.top().second.second;
            w = pq.top().first;
            //msg2(u1,u2,w)
            pq.pop();
            if(visited[u1][u2]){
               // continue;
            }
            visited[u1][u2] = 1;
            if(weight[u1][u2] < w){
                //continue;
            }

            for(i=0;i<dir;i++){
                v1 = u1 + dx[i];
                v2 = u2 + dy[i];
                //msg(uu,vv)
                if( !(v1 < 0 || v1 >= n || v2 <0 || v2 >= m) ){
                    ww = mat[v1][v2];
                    if(weight[v1][v2] > weight[u1][u2] + ww ){
                        weight[v1][v2] = weight[u1][u2] + ww ;
                        //msg2(uu,vv, weight[uu][vv])

                        pq.push(mmp(weight[v1][v2], v1,v2));
                    }
                }
            }
        }
        /*
for(int pq=0;pq<n;pq++){
    for(int PQ=0;PQ<m;PQ++){
        printf("%2d ", weight[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
        */cout << weight[n-1][m-1] << endl;


    }

    return 0;
}
