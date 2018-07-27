
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 2004
#define INF 100000
int mat[MX][MX];
int weight[MX];
int arr[MX];
int main(){
    int tc,u,v,n,m,k,i,j,ww,w,a,b,q,sz;
    pair<int,int>f;
    printf("HELLO");
    scanf("%d", &tc);
    while(tc--){

        scanf("%d%d%d", &n, &m , &k);
        vector<pair<int,int> >mat[n+1];
        for(i=0;i<=n;i++){
            arr[i] = 0;
        }
        for(i=0;i<k;i++){
            scanf("%d", &a);
            arr[a] = 1;
        }
        for(i=0;i<m;i++){
            scanf("%d%d", &u, &v);
            ww = arr[u] + arr[v];
            mat[u].push_back(make_pair(v, ww));
            mat[v].push_back(make_pair(u, ww));
            //mat[u][v] = arr[u] + arr[v];
            //mat[v][u] = arr[u] + arr[v];
        }
        scanf("%d", &q);
        while(q--){
            cin >> a >> b;

            for(i=0;i<=n;i++){
                weight[i] = INF;
            }
            priority_queue< pair<int, int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
            pq.push(make_pair(0,a));
            weight[a] = 0;
            while(!pq.empty()){
                f = pq.top();
                u = f.second;
                w = f.first;
                pq.pop();
                if(weight[u] < w){
                    continue;
                }
                sz = mat[u].size();
                for(i=0;i<sz;i++){
                    v = mat[u][i].first;
                    ww = mat[u][i].second;
                    if(weight[v] < weight[u]+ ww){
                        weight[v] = weight[u] + ww;
                        pq.push(make_pair(weight[v], v));
                    }
                }
                cout << weight[b] << endl;


            }


            /*
            st.insert(min(a,b));
            vec.push_back(make_pair(min(a,b),max(a,b)));
            */
        }
    }
    return 0;
}
