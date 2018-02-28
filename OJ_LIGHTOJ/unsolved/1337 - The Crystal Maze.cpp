#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
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
    int i,j,n,m,mq,x,y,u,v,uu,vv,mark,counter,tc,caseCounter = 1;
    map<pair<int, int>, int>mp;
    scanf("%d", &tc);
    //cin >> tc;
    while(tc--){
        vector<pair<int, int> > vec;
        queue<pair<int, int> > qq;
        cin >> n >> m >> mq;

        for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    visited[i][j] = 0;
                }
        }
        for(i=0;i<n;i++){
            scanf("%s", &mat[i]);
        }
        printf("Case %d:\n", caseCounter++);
        //cout << "Case "<< caseCounter++ << ":" << endl;
        mark = 0;
        while(mq--){
            scanf("%d%d",&x,&y);
            //cin >> x >> y;
            x--;
            y--;
            if(mat[x][y] == 'C'){
                mat[x][y] = 'D';
            }else{
                mat[x][y] = 'E';
            }
            vec.push_back(make_pair(x,y));
            mp[make_pair(x,y)] = -1;

        }
        //msg("SIZE", mp.size())
        //msg("SIZE", vec.size())
        for(j=0;j<vec.size();j++){
            x = vec[j].first;
            y = vec[j].second;
            //msg2("HL", x,y)
            if(mp[make_pair(x,y)] == -1){
                //msg2("HI", x,y)
                queue<pair<int, int> >q;
                mark++;
                counter = 0;
                qq.push(make_pair(x,y));
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
                    }else if(mat[u][v] == 'D'){
                        counter++;
                        qq.push(make_pair(x,y));
                    }else if(mat[u][v] == 'E'){
                        qq.push(make_pair(x,y));
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
            }
        while(!qq.empty()){
            uu = qq.front().first;
            vv = qq.front().second;
            qq.pop();
            mp[make_pair(uu,vv)] = counter;
        }

        }
        for(i=0;i<vec.size();i++){
            counter = mp[make_pair(vec[i].first, vec[i].second)];
            //cout << counter << endl;
            printf("%d\n", counter);
        }





    }
    return 0;
}
