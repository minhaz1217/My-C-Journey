
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
int arr[MX], p[MX];
int main(){
    int tc,u,v,n,m,k,i,j,ww,w,a,b,q,sz,temp,sum,caseCounter = 1;
    pair<int,int>f;
    //printf("HELkhLO");
    scanf("%d", &tc);
    while(tc--){
        cout << "Case "<< caseCounter++ << ":" << endl;
        scanf("%d%d%d", &n, &m , &k);
        //msg2(n,m,k)
        vector<pair<int,int> >mat[n+1];
        for(i=0;i<=n;i++){
            arr[i] = 1;
        }
        for(i=0;i<k;i++){
            scanf("%d", &a);
            arr[a] = 0;
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
            if(a==b){
                cout << 0 << endl;
                continue;
            }
            for(i=0;i<=n;i++){
                weight[i] = INF;
                p[i] = -1;
            }
            priority_queue< pair<int, int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
            pq.push(make_pair(0,a));
            weight[a] = 0;
            while(!pq.empty()){
                f = pq.top();
                u = f.second;
                w = f.first;
                pq.pop();
                //msg(u,w)
                if(weight[u] < w){
                    continue;
                }
                sz = mat[u].size();
                for(i=0;i<sz;i++){
                    v = mat[u][i].first;
                    ww = mat[u][i].second;
                    if(weight[v] > weight[u]+ ww){
                        weight[v] = weight[u] + ww;
                        //msg2("Going", u,v)
                        p[v] = u;
                        pq.push(make_pair(weight[v], v));
                    }
                }
            }
            if(weight[b] != INF){
                temp = b;
                sum = arr[b];
                while(temp!=a &&temp != -1){
                    temp = p[temp];
                    sum += arr[temp];
                }
                cout << sum << endl;
            }else{
                cout << -1 << endl;
            }


            /*
            st.insert(min(a,b));
            vec.push_back(make_pair(min(a,b),max(a,b)));
            */
        }
        cout << endl;
    }
    return 0;
}
