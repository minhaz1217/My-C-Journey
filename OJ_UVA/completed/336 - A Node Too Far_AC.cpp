#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 100
int visited[MX];
//vector<int>mat[MX];

int main(){
    int n,i,u,v,s,t,w,ss,tt,mark,nodeCounter =0,counter = 0,caseCounter = 1;
    mark = 0;
    for(i=0;i<=MX;i++){
        visited[i] = 0;
    }
    while(1){
        cin >> n;
        if(n==0){
            break;
        }
        vector<int>mat[MX];
        map<int,int>mp;
        mp.clear();
        nodeCounter = 1;
        //msg("SIZE", mp.size())
        for(i=0;i<n;i++){
            cin >> u >> v;
            if(!mp[u]){
                mp[u] = nodeCounter++;
            }
            if(!mp[v]){
                mp[v] = nodeCounter++;
            }
            mat[mp[u]].push_back(mp[v]);
            mat[mp[v]].push_back(mp[u]);
        }

        while(1){
            cin >> s >> t;
            //msg2("HI1", s,t)
            mark++;
            if(s ==0 && t == 0){
                break;
            }
            ss = mp[s];
            //msg2("HI@", ss, t)
            queue<pair<int,int> >q;
            q.push(make_pair(ss,0));
            visited[ss] = mark;
            counter = 1;
            while(!q.empty()){
                u = q.front().first;
                w = q.front().second;
                q.pop();
                if(w == t){
                    break;
                }
                for(i=0;i<mat[u].size();i++){
                    v = mat[u][i];
                    if(visited[v] != mark){
                        q.push(make_pair(v,w+1));
                       // msg2("PUSHED", u,v)
                        visited[v] =mark;
                        counter++;
                    }
                }
            }
            //msg2(nodeCounter - counter-1, s, t)
            //msg(nodeCounter , counter)
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseCounter++, (nodeCounter - counter -1), s, t);
        }

    }

    return 0;
}
