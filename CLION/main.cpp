//LCA problem
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define mx 5004
int L[mx];
int P[mx][22];
int T[mx];

vector<int> g[mx];

void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int p, int q) //node number = n
{
    int pT,qT,mp;
    pT = 0;
    qT = 0;
    while(1){
        if(p == q){
            cout << "The fleas meet at " << p << endl;
            break;
        }

        if(T[q] == -1){
            if(L[p]%2 == 0){
                mp = L[p]/ 2;
                while(mp--){
                    p = T[p];
                    //cout << p << endl;
                }
                cout << "The fleas meet at " << p << endl;
                //msg("Type1: ", p)
                break;
            }else{
                mp = L[p]/ 2;
                while(mp--){
                    p = T[p];
                    //cout << p << endl;
                }
                cout << "The fleas jump forever between " << min(p,T[p]) << " and " << max(p, T[p]) <<"." << endl;
                //msg(p, T[p])
                break;
            }
        }else{
            p = T[p];
            q = T[q];
            pT++;
            qT++;
        }
    }
}
void lca_init(int N)
{
    memset (P,-1,sizeof(P)); //settubg every to -1
    int i, j;
    for (i = 1; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 1; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}
int main()
{
    int n,a,b,i,j,l;

    while(1){
        memset(L,-1,sizeof(L));
        memset(T,-1,sizeof(T));
//        g.clear();
        cin >> n;
        if(n == 0){
            break;
        }
        for(i=0; i<n-1; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
        }
        dfs(-1,1,0);
        cin >> l;
        while(l--){
            cin >> a >> b;
            if(L[a] < L[b]){
                swap(a,b);
            }
            lca_query(a,b);
        }
        for(i=0;i<=n;i++){
            g[i].clear();
        }
    }

    return 0;
}
