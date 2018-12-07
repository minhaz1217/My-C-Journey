#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << "  : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;

#define MX 10004
bool visited[MX];


int main(){

    int tc,i,j,n,u,v,w,maxCost, maxNode,caseCounter = 1;

    cin >> tc;
    while(tc--){
        queue<pair<int, int> > q;
        cin >> n;
        vector<pair<int,int> >mat[n];
        for(i=0;i<=n;i++){
            visited[i] = 0;
        }

        for(i=0;i<n-1;i++){
            cin >> u >> v >> w;
            mat[u].push_back(make_pair(v,w));
            mat[v].push_back(make_pair(u,w));
            //msg2(u,v,w)
        }




        q.push(make_pair(u,0));
        visited[u] = 1;
        maxCost = 0;
        maxNode = u;
        while(!q.empty()){
            u = q.front().first;
            w = q.front().second;
            //msg(u,w)
            q.pop();
            if(w > maxCost){
                maxCost = max(maxCost, w);
                maxNode = u;
            }
            for(i=0;i<mat[u].size();i++){
                //msg2(u,i,mat[u][i])
                v = mat[u][i].first;
                if(!visited[v]){
                    q.push(make_pair(v,w+mat[u][i].second));
                    //msg2("HI", w, mat[u][i])
                    visited[v] = 1;
                }
            }
        }
        //msg2("Cost", maxNode, maxCost)

        for(i=0;i<=n;i++){
            visited[i] = 0;
        }

        q.push(make_pair(maxNode,0));
        visited[maxNode] = 1;
        maxCost = 0;
        while(!q.empty()){
            u = q.front().first;
            w = q.front().second;
            //msg(u,w)
            q.pop();
            if(w > maxCost){
                maxCost = max(maxCost, w);
                maxNode = u;
            }
            for(i=0;i<mat[u].size();i++){
                //msg2(u,i,mat[u][i])
                v = mat[u][i].first;
                if(!visited[v]){
                    q.push(make_pair(v,w+mat[u][i].second));
                    visited[v] = 1;
                }
            }
        }
        cout << "Case " << caseCounter++ << ": " << maxCost<< endl;






    }
    return 0;
}
