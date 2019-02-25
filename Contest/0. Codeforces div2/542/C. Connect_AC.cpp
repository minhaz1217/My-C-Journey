/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dir = 4;
int dx[] = {1,-1,0,0};
int dy[] = {0,0, 1,-1};


int dist(pair<int,int> a, pair<int,int> b){
    return (( (a.first-b.first)*(a.first-b.first) )+ ((a.second-b.second) * (a.second-b.second)) );
}

int main(){
    int n,s1,s2,d1,d2,r,c,vx,vy,minCost,mark = 1;
    char ccc;
    vector<pair<int,int> >vec1,vec2;
    int mat[55][55], visited[55][55];
    for(int i=0;i<55;i++){
        for(int j=0;j<55;j++){
            visited[i][j] = 0;
        }
    }
    cin >> n;
    cin >> s1 >> s2;
    cin >> d1 >> d2;
    s1--;
    s2--;
    d1--;
    d2--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ccc;
            mat[i][j] = ccc-'0';
            //cin >> mat[i][j];
        }
    }
    queue<pair<int,int> >q;
    q.push(make_pair(s1,s2));
    visited[s1][s2] = mark;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        vec1.push_back(make_pair(r,c));
        q.pop();
        for(int i=0;i<dir;i++){
            vx = r + dx[i];
            vy = c + dy[i];
            if( !(vx<0 || vx>=n || vy<0 || vy>=n) ){
                if(visited[vx][vy] != mark){
                    if(mat[vx][vy] == 0){
                        q.push(make_pair(vx,vy));
                        visited[vx][vy] = mark;
                    }
                }
            }
        }
    }
    mark++;
    q.push(make_pair(d1,d2));
    visited[d1][d2] = mark;
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        vec2.push_back(make_pair(r,c));
        q.pop();
        for(int i=0;i<dir;i++){
            vx = r + dx[i];
            vy = c + dy[i];
            if( !(vx<0 || vx>=n || vy<0 || vy>=n) ){
                if(visited[vx][vy] != mark){
                    if(mat[vx][vy] == 0){
                        q.push(make_pair(vx,vy));
                        visited[vx][vy] = mark;
                    }
                }
            }
        }
    }
    minCost = INT_MAX;
    if(vec1 == vec2){
        cout << 0 << endl;
    }else{
        for(int i=0;i<(int)vec1.size();i++){
            for(int j=0;j<(int)vec2.size();j++){
                minCost = min(minCost, dist(vec1[i], vec2[j]) );
            }
        }
        cout << minCost << endl;
    }


    return 0;
}
