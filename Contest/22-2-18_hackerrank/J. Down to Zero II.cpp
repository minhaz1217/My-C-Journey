#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define SV 1000009
int mark[SV+4];
int visited[SV+4];
vector<int>vec[SV];
void sieve(){
    int i,root,j;
    for(i=0;i<SV;i++){
        mark[i] = 1;
    }
    root = sqrt(SV) + 1;
    for(i=2;i<SV;i++){
        //cc(i)
        if(mark[i]){
            for(j=2;i*j<SV;j++){
                vec[i*j].push_back(max(i,j));
                //msg(i,j)
                mark[i*j] = 0;
            }
        }
    }
}
void gnrt(){
    int i,j;
    for(i=2;i<SV;i++){
        for(j=2;j<i;j++){
            if(i%j == 0){
                vec[i].push_back(max(j, i/j));
            }
        }
        //msg(i, vec[i].size())
    }
}
int main(){
    //sieve();
    //gnrt();
    sieve();

    int i,tc,n,u,v,w,mk,cost,j;
    /*
    for(i=0;i<100;i++){
        cout <<i <<  ": ";
        for(j=0;j<vec[i].size();j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    */

    cin >> tc;
    mk = 0;
    for(i=0;i<=SV;i++){
        visited[i] = mk;
    }
    mk++;

    while(tc--){
        cin >> n;
        queue<pair<int,int> >q;
        q.push(make_pair(n,0));
        visited[n] = mk;
        cost = INT_MAX;
        while(!q.empty()){
            u = q.front().first;
            w = q.front().second;
            q.pop();
            if(visited[u-1] != mk){
                q.push(make_pair(u-1,w+1));
                visited[u-1] = mk;
            }
            if(u == 0 ){
                cost = min(cost,w);
               // break;
            }
            for(i=0;i<vec[u].size();i++){
                v = vec[u][i];
                if(visited[v] != mk){
                    q.push(make_pair(v,w+1));
                    visited[v] = mk;
                }
            }
        }
        msg("ANS", cost)
        //cout << cost << endl;
        mk++;
    }




    return 0;
}
