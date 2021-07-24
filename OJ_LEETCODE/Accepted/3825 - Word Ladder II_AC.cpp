/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3825/
Date : 24 / July / 2021
Comment: leetcode hard, the problem was easy, solution was hard.
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
6 hit cog
hot dot dog lot log cog
output: will be 2 vectors

3 a c
a b c
output: [a c]

8 red tax
ted tex red tax tad den rex pee
output: will be 3 vectors of 4 words each.
*/


class Solution
{
public:
    bool mat[1004][1004];
    map<pair<string, string>, int> diffMap;
    vector<int> adj[1004];
    map<string, int> mp;
    map<int, string> revMp;

    void add_edge(vector<int> adj[], int src, int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void find_paths(vector<vector<int> >& paths,vector<int>& path,vector<int> parent[],int n, int u){
        if (u == -1){
            paths.push_back(path);
            return;
        }

        for (int par : parent[u]){
            path.push_back(u);
            find_paths(paths, path, parent,n, par);
            path.pop_back();
        }
    }

    void bfs(vector<int> adj[], vector<int> parent[], int n, int start){
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(start);
        parent[start] = { -1 };
        dist[start] = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : adj[u]){
                if (dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    parent[v].clear();
                    parent[v].push_back(u);
                }
                else if (dist[v] == dist[u] + 1){
                    parent[v].push_back(u);
                }
            }
        }
    }

    vector<vector<int> > print_paths(vector<int> adj[], int n, int start, int end){
        vector<vector<int> > paths;
        vector<int> path;
        vector<int> parent[n];
        bfs(adj, parent, n, start);
        find_paths(paths, path, parent, n, end);
//        for (auto v : paths){
//            reverse(v.begin(), v.end());
//            for (int u : v)
//                cout << u << " ";
//            cout << endl;
//        }`
        return paths;
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        set< vector<string> > allPaths;
        wordList.push_back(beginWord);
        int sz = wordList.size();
        mp[ beginWord ] = mp.size();
        revMp[ mp[beginWord] ] = beginWord;
        mp[ endWord] = mp.size();
        revMp[ mp[endWord] ] = endWord;
        for(int i=0; i<sz; i++){
            if(mp.find(wordList[i]) == mp.end()){
                mp[ wordList[i] ] = mp.size();
                revMp[ mp[wordList[i]] ] = wordList[i];
            }
        }
//        for(auto it = mp.begin(); it!= mp.end();it++){
//            msg2("HI", it->first, it->second)
//        }

        sz = wordList.size();
        for(int i=0; i<sz+4; i++)
        {
            for(int j=0; j<sz+4; j++)
            {
                mat[i][j] = 0;
            }
        }


        for(int i=0; i<sz-1; i++){
            for(int j=i+1; j<sz; j++){
                int diff = findDifference( wordList[i], wordList[j] );
                if(diff == 1){
                    // msg(wordList[i], wordList[j])
                    add_edge( adj, mp[wordList[i]], mp[wordList[j]] );
                }
            }
        }
        int src = mp[ beginWord ];
        int dest = mp[ endWord ];

//        msg2("SOURCE", src, dest)
//        for(int i=0;i<mp.size();i++){
//            cout << i << " ";
//            for(int j=0;j<adj[i].size();j++){
//                cout << " -> " << adj[i][j];
//            }
//            cout << endl;
//        }

        vector<vector<int> > paths = print_paths(adj, mp.size()+1, src, dest);
        for(int i=0;i<paths.size();i++){
//            paths[i].push_back(src);
            reverse(paths[i].begin(), paths[i].end());
//            paths[i].push_back(dest);
            vector<string> path;
            for(int j=0;j<paths[i].size();j++){
                // cout << revMp[ paths[i][j] ] << " ";
                path.push_back(revMp[ paths[i][j] ]);
            }
            // cout << endl;
            allPaths.insert(path);
        }
        vector<vector<string > > result;
        for(auto it = allPaths.begin();it != allPaths.end();it++){
            result.push_back( *it );
        }
        return result;
    }
    int findDifference(string str1, string str2)
    {
        int sz = str1.size(), counter = 0;
        for(int i=0; i<sz; i++)
        {
            if(str1[i] != str2[i])
            {
                counter++;
            }
            if(counter > 1)
            {
                return 0;
            }
        }
        if(counter == 1)
        {
            return 1;
        }
        return 0;
    }

};

int main()
{
    int n;
    string str, beginWord, endWord;
    vector<string> wordList;

    cin >> n >> beginWord >> endWord;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        wordList.push_back(str);
    }
    Solution solution;
    vector<vector<string> > result = solution.findLadders(beginWord, endWord, wordList);



    return 0;
}
