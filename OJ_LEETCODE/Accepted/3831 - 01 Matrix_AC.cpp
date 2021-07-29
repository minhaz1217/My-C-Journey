/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3831/
Date : 29 / July / 2021
Comment:
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

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int> > visited;
        int sr = mat.size();
        int sc = mat[0].size();
        for(int i=0;i<sr;i++){
            vector<int> vec( mat[i].size(), INT_MAX );
            visited.push_back(vec);
        }
        priority_queue<pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > q;
        for(int i=0;i<sr;i++){
            for(int j=0;j<sc;j++){
                if(mat[i][j] == 0){
                    q.push( make_pair(0, make_pair(i,j) ) );
                    visited[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int w = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            //cout << x << " " << y << " "<< w << endl;
            visited[x][y] = w;
            q.pop();
            for(int i=0;i<4;i++){
                int vx = x + dx[i];
                int vy = y + dy[i];
                if( !(vx < 0 || vy <0 || vx >= sr || vy >= sc) ){
                    if(mat[vx][vy] == 1 && visited[vx][vy] == INT_MAX ){
                        q.push( make_pair(w+1, make_pair(vx,vy)) );
                        visited[vx][vy] = w+1;
                    }
                }
            }

        }


        return visited;
    }
};

int main(){

    return 0;
}
