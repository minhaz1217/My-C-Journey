#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,n,u,v,i,j,nodeCount,caseCounter = 1,currMax, currMin;
    cin >> tc;
    while(tc--){
        nodeCount = 0;
        currMax = 0;
        currMin = 0;
        cin >> n;
        vector<int> mat[20005];
        for(i=1;i<=n;i++){
            cin >> u >> v;
            //[max(u,v)].push_back(min(u,v));
            mat[u].push_back(v);
            mat[v].push_back(u);
            nodeCount = max(nodeCount, max(u,v));
        }
        int t[3] = {0};
        int visited[nodeCount+4];
        int color[nodeCount+4];
        for(i=0;i<nodeCount+4;i++){
            visited[i] = 0;
            color[i] = 0;
        }
        //msg("HI", nodeCount)
        queue<int> q;
        for(i=1;i<= nodeCount;i++){
            if(!visited[i] && mat[i].size() > 0){
                q.push(i);
                visited[i] = 1;
                color[i] = 2;
                t[color[i]]++;
                while(!q.empty()){
                    u = q.front();
                    //tag = q.front();
                    //check(u)
                    q.pop();
                    for(j=0;j<mat[u].size();j++){
                        v = mat[u][j];
                           // cout << "VISITED " << v << " FROM " <<  u << endl;
                        if(!visited[v]){
                            if(color[u] == 2){
                                color[v] = 1;
                            }else{
                                color[v] = 2;
                            }
                            //color[v] = color[u] - 1;
                            t[color[v] ]++;
                            visited[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
            if(t[1] > t[2]){
                t[1] += currMax;
                t[2] += currMin;
            }else{
                t[1] += currMin;
                t[2] += currMax;
            }
            currMax = max(t[1], t[2]);
            currMin = min(t[1], t[2]);
            t[1] = 0;
            t[2] = 0;

        }
        /*
    for(i=1;i<=nodeCount;i++){
        //msg(i, color[i])
    }
    */

    //msg(currMax, currMin);
    cout <<"Case " << caseCounter++ << ": " <<  currMax << endl;

    }

    return 0;
}
