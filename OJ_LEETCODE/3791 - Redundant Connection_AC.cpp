/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3791/
Date : 27 / June / 2020
Comment: Disjoint set problem.
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

// Input
/*
[[1,2],[1,3],[2,3]]
[[2,3],[1,3],[1,2]]
*/
// Output
/*
[2,3]
[1,2]
*/
class DisjointSet{
    vector<int> p,rt;
public:
    DisjointSet(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i; // everyone's parent is him only.
        }
    }

    /// Finding the parent of this node.
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]); /// finding the parent and also storing it for later use.
            return p[x];
        }
    }

    /// Returns true if both of these belong in the same set.
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }

    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){ /// if rating of a is greater than b, we make a the parent of b
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){ /// if both of their rating is same, we increase b's rating.
                    rt[b]++;
                }
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        vector<pair< pair<int,int> ,int> > myCustomEdges;
        for(int i=0;i<edges.size();i++){
            myCustomEdges.push_back( make_pair( make_pair(edges[i][0], edges[i][1]), i ) );
        }
        DisjointSet disjointSet(1002);
        int x,y, currentMax = INT_MIN;
        //sort(myCustomEdges.begin(),myCustomEdges.end());
        for(int i=0;i<myCustomEdges.size();i++){
            int u = myCustomEdges[i].first.first;
            int v = myCustomEdges[i].first.second;
            if(!disjointSet.isSameSet(u, v)){
                disjointSet.unionSet(u, v);
            }else if(currentMax <= myCustomEdges[i].second){
                x = u;
                y = v;
                currentMax = myCustomEdges[i].second;
            }
        }
        vector<int> result;
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};

int main(){

    return 0;
}
