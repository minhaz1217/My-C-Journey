#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 999*999
#define INF 500000
int weight[MX+2];
int main(){
    int tc,i,j,n,m,a,w,nod,u,v,s,ww;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        vector<pair<int,int> >mat[n*m+2];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> w;
                nod = m*i + j;
                weight[nod] = w;
                v= nod;
                //mat[nod].push_back(make_pair(nod,w));
                //cc(w)
                if(i > 0){
                    u = m*(i-1) + j;
                    //msg2(u,v,w)
                    mat[u].push_back(make_pair(v,w));
                   // mat[v].push_back(make_pair(u,w));
                }
                //cc("HI")
                if(j > 0){
                    u = m*(i) + (j-1);
                    //msg2(u,v,w)
                    mat[u].push_back(make_pair(v,w));
                   // mat[v].push_back(make_pair(u,w));

                }
               // cc("HI2")
                if(i<n-1){
                    u = m*(i+1) + j;
                    //msg2(u,v,w)
                    mat[u].push_back(make_pair(v,w));
                    //mat[v].push_back(make_pair(u,w));

                }
                //cc("HI2")
                if(j<m-1){
                    u = m*i + (j+1);
                    //msg2(u,v,w)
                    mat[u].push_back(make_pair(v,w));
                    //mat[v].push_back(make_pair(u,w));
                }

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

        for(i=1;i<=n*m;i++){
            weight[i] = INF;
        }
        s = 0;
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > >pq;
        pq.push(make_pair(weight[s],s));
        //weight[s] = 0;
        while(!pq.empty()){
            u = pq.top().second;
            w = pq.top().first;
            pq.pop();
            if(weight[u] < w){
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
        cout << weight[n*m-1] << endl;


    }

    return 0;
}
