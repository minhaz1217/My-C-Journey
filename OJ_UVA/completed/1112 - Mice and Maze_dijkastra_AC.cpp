#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define inf 50000
int main(){
    int tc,n,s,t,m,u,v,w,ww,i,counter,myC = 1,j;
    pair<int, int> f;
    cin >> tc;
    while(tc--){
        cin >> n >> s >> t >> m;
        if(myC > 1){
            cout << endl;
        }
        myC++;
        vector<pair<int,int> >mat[n+1];
        int weight[n+1];
        for(i=1;i<=m;i++){
            cin >> u >> v >> w;
            mat[u].push_back(make_pair(v,w));
        }
        for(i=0;i<=n;i++){
            weight[i] = inf;
        }
        counter = 0;
        for(j=1;j<=n;j++){
            for(i=0;i<=n;i++){
                weight[i] = inf;
            }
            weight[j] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
            pq.push(make_pair(0,j));
            while(!pq.empty()){
                f = pq.top();
                w = f.first;
                u = f.second;
                pq.pop();
                for(i=0;i<mat[u].size();i++){
                    v = mat[u][i].first;
                    ww = mat[u][i].second;
                    if(weight[v] > weight[u] + ww){
                        weight[v] = weight[u] + ww;
                        pq.push(make_pair(weight[v], v));
                    }
                }
            }
            if(weight[s] <= t){
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
