#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


pair<int, pair<int,int> >mmp(int a,int b, int c){
 return make_pair(a, make_pair(b,c));
}

int main(){
    int n,m,k,s,t,u,v,l,r,i;
    cin >> n >> m >> k;
    cin >> s >> t;
    vector<pair<int,pair<int,int> > >mat[n+2];
    //pair<int,int> mat[n+2][n+2];

    for(i=0;i<m;i++){
        cin >> u >> v >> l >> r;

        mat[u].push_back(mmp(v,l,r));
    }

    q.push(mmp(s, 1,k));
    visited[s] = 1;
    while(!q.empty()){
        f = q.front();
        u = f.first;
        l = f.second.first;
        r = f.second.second;
        q.pop();
        for(i=0;i<mat[u].size();i++){
            ff = mat[u][i];
            v = ff.first;
            ll = ff.second.first;
            rr = ff.second.second;
            if(l < ll){
                l = ll;
            }
            if(r > rr){
                r = rr;
            }
            q.push(mmp(v,l,r));
            visited[v]
        }

    }



    return 0;
}
