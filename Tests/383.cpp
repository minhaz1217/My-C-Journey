#include <bits/stdc++.h>
using namespace std;
#define N 40
#define inf -1
//map <string,vector <string> >graph;
//map <string,int> dist;
//map <string,int> visit;
int m,n,p,cost;
int dist[N], visit[N];
vector <int> graph[N];
int bfs(int src,int des)
{
    memset(dist,-1,sizeof(dist));
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    visit[src] = 1;
    bool finder = false;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(!visit[v])
            {
                visit[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[des];
}
/*void print1(){
 for(map <string,int> ::iterator it =dist.begin();it!=dist.end();it++){
     cout << it-> second << endl;
 }
}*/
/*void print2(){
    for(int i = 1;i<=N;i++){
        cout << dist[i] << endl;
    }
}*/
int main()
{
    int t;
    char s[30];
    string a,b;
    scanf("%d",&t);
    cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
    map <string,int> mp;
    for(int i = 1; i<=t; i++)
    {

        scanf("%d%d%d",&m,&n,&p);
        printf("DATA SET %d\n\n",i);
        for(int j = 1; j<=m; j++)
        {
            cin >> s;
            mp[s] = j;
        }
        for(int k = 1; k<=n; k++)
        {
            cin >> a >> b;
            graph[mp[a]].push_back(mp[b]);
            graph[mp[b]].push_back(mp[a]);
        }
        string c,d;
        int cost1;
        for(int l = 1; l<=p; l++)
        {
            cin >> cost >> a >> b;
            cost1 = bfs(mp[a],mp[b]);
            //print();
            if(cost1== -1 || n==0)
            {
                cout<< "NO SHIPMENT POSSIBLE" << endl ;
            }
            else
            {
              cout << "$" <<  cost*cost1*100 << endl;
            }
        }
       cout << endl;
    }
    cout << "END OF OUTPUT" ;
    return 0;
}
