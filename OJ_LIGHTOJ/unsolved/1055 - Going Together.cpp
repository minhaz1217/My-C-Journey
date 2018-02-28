#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int visited[MX][MX];
int dir = 4;
int dx = {0,0,1,-1};
int dy = {1,-1,0,0};
void makeVisited(vector<pair<int, int> > v){
    for(int i=0;i<v.size();i++){
        visited[v[i].first]  =1;
        visited[v[i].second]  =1;
    }
}




int main(){
    vector<pair<int, int> > vsol;
    vector<pair<int, int> > vbot,u;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin >> mat[i][j];
                visited[i][j] = 0;
                if(mat[i][j] == 'A'){
                    vbot.push_back(make_pair(i,j));
                }else if(mat[i][j] == 'B'){
                    vbot.push_back(make_pair(i,j));
                }else if(mat[i][j] == 'C'){
                    vbot.push_back(make_pair(i,j));
                }else if(mat[i][j] == 'X'){
                    vsol.push_back(make_pair(i,j));
                }
            }
        }
        queue<vector<pair<int,int> > >q;
        q.push(vbot);
        makeVisited(vbot);
        while(!q.empty()){
            u = q.front();
            for(j=0;j<dir;j++){
                for(i=0;i<u.size();i++){
                    x = u[i].first;
                    y = u[i].second;
                    cx = x+ dx[j];
                    cy = y + dy[j];
                    if(cx >=0 && cx<n && cy >=0 && cy<n){
                        if(mat[cx][cy] == 'A')
                    }
                }
            }
        }






    }
    return 0;
}
