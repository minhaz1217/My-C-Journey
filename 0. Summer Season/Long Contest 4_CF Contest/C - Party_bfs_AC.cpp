#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i,a,highestCost, j,u,v,w,s;
    cin >> n;
    vector<int> mat[n+1], root;
    int visited[n+1];
    for(i=1;i<=n;i++){
        cin >> a;
        if(a != -1){
            mat[i].push_back(a);
            mat[a].push_back(i);
        }else{
            root.push_back(i);
        }
    }
    highestCost = INT_MIN;

    for(i=0;i<root.size();i++){
        s = root[i];
        for(j=0;j<=n;j++){
            visited[j] = 0;
        }
        queue<pair<int,int> >q;
        q.push(make_pair(s,1));
        visited[s] = 1;
        while(!q.empty()){
            u = q.front().first;
            w = q.front().second;
            highestCost = max(highestCost, w);
            q.pop();
            for(j=0;j<mat[u].size();j++){
                v = mat[u][j];
                if(!visited[v]){
                    q.push(make_pair(v,w+1));
                    visited[v] = 1;
                }
            }
        }
    }
    cout << highestCost << endl;


    return 0;
}
