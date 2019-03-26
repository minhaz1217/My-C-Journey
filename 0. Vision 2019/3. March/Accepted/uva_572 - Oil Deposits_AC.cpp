/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-572#author=felixj
Date : 26 / March / 2019
Comment: Easy basic flood fill
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
#define MX 105
int dir = 8;
int dx[] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[] = {0,  0, 1, -1, 1, -1,  1, -1};
char mat[MX][MX];
int visited[MX][MX];
int main(){
    int n,m,counter,u,v,du,dv,su,sv;
    while(1){
        vector<pair<int,int> > vec;

        cin >>n >> m;
        if(n ==0 && m == 0){
            break;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                visited[i][j] = 0;
                if(mat[i][j] == '@'){
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        counter = 0;
        for(int i=0;i<vec.size();i++){
            u = vec[i].first;
            v = vec[i].second;
            if( visited[u][v] == 0 ){
                counter++;
                queue<pair<int,int> >q;
                q.push(make_pair(u,v));
                visited[u][v] = 1;
                while(!q.empty()){
                    su = q.front().first;
                    sv = q.front().second;
                    q.pop();
                    for(int j=0;j<dir;j++){
                        du = su + dx[j];
                        dv = sv + dy[j];
                        if( !(du<0 || dv<0 || du>=n || dv>=m) ){
                            if(mat[du][dv] == '@' && !visited[du][dv]){
                                q.push(make_pair(du,dv));
                                visited[du][dv] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << counter << endl;


    }
    return 0;
}
