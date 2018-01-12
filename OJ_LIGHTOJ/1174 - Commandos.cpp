#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int mat[10005][10005];
int n,m,s,d;

int bfs(){

    int counter = 0, ss,i,myC;
    int visited[n] = {0};
    myC = n;
    stack<int> q;
    q.push(s);
    while(!q.empty()){
        ss = q.top();
        q.pop();
        cout << ss << endl;
        if(ss == d && myC != 1){
            q.push(ss);
            continue;
        }


        visited[ss] = 1;
        for(i=0;i<n;i++){
            if(mat[ss][i] == 1 && !visited[i]){
                q.push(i);
            }
        }
    }
    msg(counter, myC)
    //cout << counter << endl;

}






int main(){
    int tc,a,b;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        while(m--){
            cin >> a >> b;
            mat[a][b] = 1;
            mat[b][a] = 1;
        }
        cin >> s >> d;
        bfs();





    }

    return 0;
}
