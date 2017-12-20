/**Bismillahir Rahmanir Rahim.**/

#include <bits/stdc++.h>

using namespace std;

vector<int> node[110];
int vis[110];

int BFS(int x)
{
    queue<int> Q;
    memset(vis, 0, sizeof(vis));
    vis[x] =  1;
    Q.push(x);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for(int i=0; i<node[now].size(); i++)
        {
            int y = node[now][i];
            if(y==x)
                return 0;
            if(vis[y]!=0) continue;

            vis[y] = 1;
            Q.push(y);
        }
    }
    return 1;
}
int main()
{
    int tst, N, M, x, y;
    scanf("%d", &tst);
    for(int i = 1; i<=tst; i++)
    {
        int ans = 0;
        scanf("%d %d", &N, &M);
        for(int ii=1; ii<=M; ii++)
        {
            scanf("%d%d", &x, &y);
            node[x].push_back(y);
        }
        for(int ii=1; ii<=N; ii++)
        {
            if(node[ii].size()==0) ans++;
            else ans += BFS(ii);
        }
        printf("Case %d: %d\n", i, ans);
        for(int ii=0; ii<110; ii++)
            node[ii].clear();
    }
    return 0;
}
