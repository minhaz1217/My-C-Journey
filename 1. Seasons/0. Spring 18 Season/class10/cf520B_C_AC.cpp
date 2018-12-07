#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << "  : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;

#define MX 10000004
bool visited[MX] = {0};

int main(){
    int n,m,u,v,cost = 0,i;
    queue<pair<int, int> >q;
    cin >> n >> m;
    for(i=0;i<=m+10;i++){
        visited[i] = 0;
    }
    if(m <= n){
        cout << n-m << endl;
    }else{
        q.push(make_pair(n,0));
        visited[n] = 1;
        cost = INT_MAX;
        //msg("HI", 1)
        while(!q.empty()){
            u = q.front().first;
            v = q.front().second;
            q.pop();
            if(u == m){
                cost = min(cost, v);
                //msg("F", v)
                break;
            }
            //msg(u, v);
            if(u*2 <= 2*m && !visited[u*2]){
                q.push(make_pair(u*2, v+1));
                visited[u*2] = 1;
            }
            if(u-1 >= 0 && !visited[u-1]){
                q.push(make_pair(u-1, v+1));
                visited[u-1] = 1;
            }
        }
        cout << cost << endl;
    }




    return 0;
}
