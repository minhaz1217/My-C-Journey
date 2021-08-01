/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 01 / June / 2021
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
/*
2
1 0
0 1
output: 3
2
1 1
1 0
output: 4
2
1 1
1 1
output: 4
2
0 1
1 1
output : 4
*/
class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }

};
class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int getUniqueCellIdentity(int i, int j, int sz){
        return i*sz + j;
    }
    int largestIsland(vector<vector<int>>& grid) {
        disjoint_set dj(250004);
        int sz = grid.size(),counter, mx = INT_MIN;
        map<int,int> mp;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int vx = i + dx[k];
                        int vy = j + dy[k];
                        if( !(vx < 0 || vx >= sz || vy < 0 || vy >= sz) ){
                            if(grid[vx][vy] == 1){
                                dj.unionSet( getUniqueCellIdentity(i,j,sz), getUniqueCellIdentity(vx,vy,sz) );
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                int p = dj.findSet(getUniqueCellIdentity(i,j,sz));
                if(mp.find(p) == mp.end()){
                    mp[p] = 0;
                }
                mp[p]++;
                mx = max(mx, mp[p]);
            }
        }

        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(grid[i][j] == 0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int vx = i + dx[k];
                        int vy = j + dy[k];
                        if( !(vx < 0 || vx >= sz || vy < 0 || vy >= sz) ){
                            if(grid[vx][vy] == 1){
                                st.insert(dj.findSet(getUniqueCellIdentity(vx,vy,sz)) );
                            }
                        }
                    }
                    counter = 0;
                    for(set<int>::iterator it = st.begin(); it!= st.end();it++){
                        counter += mp[ *it ];
                    }
                    mx = max(mx, counter+1);
                }
            }
        }
        return mx;
    }
};

int main(){
    int n,a;
    vector<vector<int> > vecc;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> vec;
        for(int j=0;j<n;j++){
            cin >> a;
            vec.push_back(a);
        }
        vecc.push_back(vec);
    }
    Solution solution;
    cout << "ANS: " << solution.largestIsland(vecc) << endl;
    return 0;
}
