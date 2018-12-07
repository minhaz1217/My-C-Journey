#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 304
int mat[MX][MX];
int visited[MX], p[MX];
int main(){
    char c;
    string str;
    int n,i,a,j,s,d,qq,found,u,temp;
    while(cin >> n){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                mat[i][j] =0;
            }
            visited[i] = 0;
            p[i] = -1;
        }
        for(i=1;i<=n;i++){
            cin >> str;
            stringstream ss(str);
            while(ss>>a){
                //cc(a)
                if(a != i){
                    mat[i][a] = 1;
                    //mat[a][i] = 1;
                }
                ss>>c;
            }
        }
/*
for(int pq=0;pq<=n;pq++){
    for(int PQ=0;PQ<=n;PQ++){
        printf("%2d ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/
        cout << "-----" << endl;
        cin >> qq;
        while(qq--){
            cin >> s >> d;
            //msg2("SS", s,d)
            for(i=1;i<=n;i++){
                visited[i] = 0;
                p[i] = -1;
            }
            queue<int>q;
            q.push(s);
            visited[s] = 1;
            //msg(s,d)
            found = 0;
            while(!q.empty()){
                u = q.front();
                q.pop();
                if(u==d){
                    found = 1;
                    break;
                }
                for(i=1;i<=n;i++){
                    if(!visited[i] && mat[u][i]){
                        q.push(i);
                        p[i] = u;
                        //msg2("PUSHED", i, u)
                        visited[i] = 1;
                    }
                }
            }
            if(found==0){
                cout << "connection impossible" << endl;
            }else{
                stack<int>mq;
                temp = d;
                mq.push(d);
                while(temp != s){
                    mq.push(p[temp]);
                    temp = p[temp];
                }
                cout << mq.top();
                mq.pop();
                while(!mq.empty()){
                    cout << " " << mq.top();
                    mq.pop();
                }
                cout << endl;
            }
        }

    }

    return 0;
}
