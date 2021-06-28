/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/submissions/detail/514565398/?from=explore&item_id=3785
Date : 29 / June / 2021
Comment: modified dijkastra?
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
/*
5
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6
output: 16

5
 0  1  2  3  4
24 23 22 1  5
12 13 14 1 16
11 17 8 1 20
10  9  8  7  6
output: 7

2
0 2
1 3
output: 3

3
1 1 1
1 5 2
1 1 4

*/

class Solution {
public:
    int swimInWater(vector<vector<int> >& grid) {
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int sz = grid.size();
        int distance[sz+1][sz+1], visited[sz+1][sz+1];
        int result = grid[0][0];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                distance[i][j] = grid[i][j];
                visited[i][j] = false;
            }
        }

        priority_queue<pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >, std::greater<pair<int,pair<int,int> > > > q;
        q.push(make_pair(distance[0][0],make_pair(0,0))); /// weight 0, node 0,0
        while(!q.empty()){
            int i = q.top().second.first;
            int j = q.top().second.second;
            int w = q.top().first;
            q.pop();
            if(i == sz-1 && j == sz-1){
                result = w;
                break;
            }
            //msg2(i,j,w)
            if(distance[i][j] < w || visited[i][j]){
                continue;
            }
            for(int k=0;k<4;k++){
                if( !(i+dx[k] >= sz || i+dx[k] < 0 || j+dy[k] >=sz || j+dy[k]<0 )){
                    if(!visited[i+dx[k]][j+dy[k]]){
                        distance[i+dx[k]][j+dy[k]] = max(distance[i+dx[k]][j+dy[k]], distance[i][j]);
                        //msg3("K", i+dx[k], j+dy[k], distance[i+dx[k]][j+dy[k]])
                        q.push(make_pair(distance[i+dx[k]][j+dy[k]], make_pair(i+dx[k], j+dy[k])));
                    }
                }
            }
            visited[i][j] = true;
        }
        return result;
    }
};
int main(){
    int n,a;
    cin >> n;
    vector< vector<int> > mat;
    for(int i=0;i<n;i++){
        vector<int> vec;
        for(int j=0;j<n;j++){
            cin >> a;
            vec.push_back(a);
        }
        mat.push_back(vec);
    }
    Solution solution;
    cout << solution.swimInWater(mat) << endl;
}

