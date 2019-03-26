/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10305
Date : 27 / March / 2019
Comment: Easy topological sorting
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int>adj[105];
vector<int>tp;
int visited[105];
void dfs(int u){
    int v;
    for(int i=0;i<adj[u].size();i++){
        v = adj[u][i];
        if(!visited[v]){
            visited[v] = 1;
            dfs(v);
        }
    }
    tp.push_back(u);
}



int main(){
    int n,m,u,v;
    while(1){

        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        for(int i=1;i<=n;i++){
            adj[i].clear();
            visited[i] = 0;
        }
        tp.clear();
        for(int i=0;i<m;i++){
            cin >> u >> v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(i);
            }
        }
        reverse(tp.begin(), tp.end());
        for(int i=0;i<tp.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << tp[i];
        }
        cout << endl;
    }



    return 0;
}
