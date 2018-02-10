#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 14

char mat[MX][MX];
int r,c,dir = 8;
int dr[] = {1,1,2,2,-1,-1,-2,-2};
int dc[] = {2,-2,1,-1,2,-2,1,-1};
int field[MX][MX];
int myVisited[MX][MX];
pair<int, pair<int, pair<int, int> > > makePair(int x,int y, int v, int rr){
    return make_pair(x, make_pair(y, make_pair(v, rr)));
}


void bfs(int x,int y){

    pair<int, pair<int, pair<int, int> > >u;
    int visited[r][c],i,j,xx,yy,cc,cr,tc,tr;
    int originalCost = mat[x][y] - '0';
    //cout << x << " " << y << " " << originalCost << endl;
    int round = 0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            visited[i][j] = 0;
        }
    }
    queue<pair<int, pair<int, pair<int, int> > > >q;
    visited[x][y] = 1;
    //myVisited[x][y]++;
    //field[x][y]++;
    q.push(makePair(x,y,0,0));
    while(!q.empty()){
        u = q.front();
        xx = u.first;
        yy = u.second.first;
        cc = u.second.second.first;
        cr = u.second.second.second;
        //cout << cc << cr << endl;
        q.pop();
        if(field[xx][yy]< 0){
            field[xx][yy] = cr;
        }else{
            field[xx][yy] += cr;
        }

//cout << xx << "," << yy << ": " << cc << " " << cr<< endl;
/*for(int mq=0;mq<r;mq++){
    for(int nq=0;nq<c;nq++){
        printf("%2d ", field[mq][nq]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}*/



        myVisited[xx][yy]++;
        for(i=0;i<dir;i++){
            tr = dr[i] + xx;
            tc = dc[i] + yy;
            if(tr >=0 && tr < r && tc >=0 && tc<c ){
                if(!visited[tr][tc]){
                    if(cc-1<=0){
                        q.push(makePair(tr,tc, originalCost, cr+1));
                    }else{
                        q.push(makePair(tr,tc, cc-1, cr));
                    }
                    //msg(tr, tc)
                    visited[tr][tc] = 1;
                    //myVisited[tr][tc]++;
                }
            }
        }
    }
//exit(0);
/*
cout << "HELLO" << endl;
msg(x,y)
check(originalCost)
for(int mq=0;mq<r;mq++){
    for(int nq=0;nq<c;nq++){
        printf("%2d ", field[mq][nq]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
cout << endl << endl;
*/

}


int main(){
    int tc,i,j,mq,nq,caseCounter = 1;
    cin >> tc;
    while(tc--){
    vector<pair<int, int> >v;
        //v.empty();
        cin >> r >> c;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                field[i][j] = -9;
                myVisited[i][j] = 0;
                mat[i][j] = '\0';
            }
        }


        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin >> mat[i][j];
                if(mat[i][j] != '.'){
                    v.push_back(make_pair(i,j));
                }
            }
        }
        //check(v.size())
        for(i=0;i<v.size();i++){
            bfs(v[i].first, v[i].second);
        }
        int currMin = INT_MAX,foundOne = 0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(myVisited[i][j] == v.size()){
                    foundOne = 1;
                    currMin = min(currMin, field[i][j]);
                }
            }
        }
        if(foundOne && currMin >= 0){
            cout << "Case "<< caseCounter++ << ": " << currMin << endl;
        }else{
            cout << "Case "<< caseCounter++ << ": " << -1 << endl;
        }


    }

    return 0;
}
