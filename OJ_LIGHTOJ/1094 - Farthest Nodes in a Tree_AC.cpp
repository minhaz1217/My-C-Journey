#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define MX 30005
int visited[MX];

int main(){
    int tc,nodes,u,v,w,i,nod,myMax=INT_MIN, c,big,caseCounter=1;
    queue<pair<int, int> > q;
    cin >> tc;
    while(tc--){
        cin >> nodes;

        big = 0;
        myMax = INT_MIN;
        vector<pair<int, int> >mat[nodes+1];
        for(i=0;i<nodes-1;i++){
            cin >> u >> v >> w;
            mat[u].push_back(make_pair(v,w));
            mat[v].push_back(make_pair(u,w));

        }
        pair<int, int> uu;
        for(i=0;i<=nodes;i++){
            visited[i] = 0;
        }

        q.push(make_pair(0, 0));
        visited[0] = 1;
        while(!q.empty()){
            uu = q.front();
            u = q.front().first;
            c = q.front().second;
            if(c>=myMax){
                myMax = c;
                big = u;
            }
            q.pop();
            for(i=0;i<mat[u].size();i++){
                if(!visited[mat[u][i].first]){
                    q.push(make_pair(mat[u][i].first, mat[u][i].second+c));
                    visited[mat[u][i].first] = 1;
                }
            }
        }
        //msg(big, myMax)
        for(i=0;i<=nodes;i++){
            visited[i] = 0;
        }
        q.push(make_pair(big, 0));
        visited[big] = 1;
        big = 0;
        myMax = INT_MIN;
        while(!q.empty()){
            uu = q.front();
            u = q.front().first;
            c = q.front().second;
            if(c>=myMax){
                myMax = c;
                big = u;
            }
            q.pop();
            for(i=0;i<mat[u].size();i++){
                if(!visited[mat[u][i].first]){
                    q.push(make_pair(mat[u][i].first, mat[u][i].second+c));
                    visited[mat[u][i].first] = 1;
                }
            }
        }
        cout << "Case "<< caseCounter++ << ": "<< myMax << endl;

        //msg(myMax, big);
    }

    return 0;
}
