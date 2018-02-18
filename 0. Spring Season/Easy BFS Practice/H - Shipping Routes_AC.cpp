#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 35
int visited[MX];
int main(){
    int tc,n,m,qq,i,u,v,j,w,s,d,a,cost,dataCounter = 1;
    string str1, str2,str;

    cin >> tc;
    cout << "SHIPPING ROUTES OUTPUT" << endl;
    while(tc--){

        cout << endl << "DATA SET  "<< dataCounter++ << endl<< endl;
        cin >> n >> m >>qq;
        int mat[n+2][n+2];
        map<string,int>mp;
        for(i=1;i<=n;i++){
            cin >> str;
            mp[str] = i;
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = 0;
            }
        }
        for(i=0;i<m;i++){
            cin >> str1 >> str2;
            u = mp[str1];
            v = mp[str2];
            mat[u][v] = 1;
            mat[v][u] = 1;
        }
        while(qq--){
            cin >> a >> str1 >> str2;
            s = mp[str1];
            d = mp[str2];
            for(i=1;i<=n;i++){
                visited[i] = 0;
            }
            queue<pair<int, int> >q;
            q.push(make_pair(s,0));
            visited[s] = 1;
            cost = -1;
            while(!q.empty()){
                u = q.front().first;
                w = q.front().second;
                q.pop();
                if(u == d){
                    cost = w;
                    break;
                }
                for(i=1;i<=n;i++){
                    if(mat[u][i] && !visited[i]){
                        q.push(make_pair(i, w+1));
                        visited[i] = 1;
                    }
                }
            }
            if(cost == -1){
                cout << "NO SHIPMENT POSSIBLE"<< endl;
            }else{
                cout << "$" << cost*a*100 << endl;
            }
            //msg2("RES", cost, cost*a*100)

        }

    }
    cout << endl << "END OF OUTPUT" << endl;
    return 0;
}
