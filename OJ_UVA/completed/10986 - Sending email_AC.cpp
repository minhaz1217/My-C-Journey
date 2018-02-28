#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 20004
#define INF 50000
int mat[MX][MX];
int weight[MX];



int main(){
    int tc,i,n,m,s,t,u,v,ww,w,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n >> m >> s >> t;

        vector<pair<int,int> >mat[n+1];
        for(i=0;i<=n;i++){
            weight[i] = INF;
        }

        while(m--){
            cin >> u >> v >> w;
            mat[u].push_back(make_pair(v,w));
            mat[v].push_back(make_pair(u,w));
        }

        priority_queue<pair<int,int>, vector< pair<int,int> > , greater< pair<int,int> > >pq;
        pq.push(make_pair(0,s));
        weight[s] = 0;

        while(!pq.empty()){
            u = pq.top().second;
            w = pq.top().first;
            pq.pop();
            if(w > weight[u]){
                continue;
            }

            for(i=0;i<mat[u].size();i++){
                v = mat[u][i].first;
                ww = mat[u][i].second;
                if(weight[v] > weight[u] + ww){
                    weight[v] = weight[u] + ww;
                    pq.push(make_pair(weight[v], v));
                }
            }
        }
        if(weight[t] == INF){
            cout << "Case #" << caseCounter++<< ": unreachable" << endl;
        }else{
            cout << "Case #" << caseCounter++<< ": " << weight[t] << endl;
        }
    }


    return 0;
}
