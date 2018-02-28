#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define INF 500000
#define MX 104
int mat[MX][MX];
int weight[MX], p[MX];


int main(){
    int n,i,j,u,v,ww,w,s,t,a,caseCounter =1 ;


    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = INF;
            }
            mat[i][i] = 0;
            weight[i] = INF;
            p[i] = -1;
        }
        for(i=1;i<=n;i++){
            cin >> a;
            u = i;
            while(a--){
                cin >> v >> w;
                mat[u][v] = min(w,mat[u][v]);
                //msg2(u,v,w)
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
        cin >> s >> t;

        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> >  >q;
        pair<int,int>f;
        q.push(make_pair(0,s));
        weight[s] = 0;
        while(!q.empty()){
            f = q.top();
            w = f.first;
            u = f.second;
            q.pop();
            //msg(w,u)
            if(weight[u] < w){
              //  continue;
            }
            for(i=1;i<=n;i++){
                ww = mat[u][i];
                v = i;
                if(mat[u][v]!=INF && weight[v] > weight[u] + ww){
                    weight[v] = weight[u] + ww;
                    q.push(make_pair(weight[v], v));
                    p[v] = u;
                }
            }
        }
        printf("Case %d: Path =", caseCounter++);

        stack<int> st;
        st.push(t);
        int temp;
        temp = t;
        while(temp!= s){
            temp = p[temp];
            st.push(temp);
        }
        while(!st.empty()){
            cout << " " << st.top();
            st.pop();
        }
        printf("; %d second delay\n", weight[t]);



    }
    return 0;
}
