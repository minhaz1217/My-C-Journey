/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / November / 2019
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


#define MX 100004
vector<int > adj[MX];
vector<pair<int,int> > vec,vec2;
vector<int>searchList,connected;
bool mark[MX];
bool currConnected[MX];
int main(){

    long long int a,k,counter,n,m,u,v,found,mnNode;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if( m == 0){
        cout << 0 << endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        vec2.push_back( {adj[i].size(), i} );
    }

    mnNode = vec2[0].second;
    //cc("HI")
    for(int i=0;i<adj[mnNode].size();i++){
        mark[ adj[mnNode][i] ] = 1;
    }
    for(int i=1;i<=n;i++){
        if(mark[i] == 0){
            connected.push_back(i);
        }else{
            searchList.push_back(i);
        }
    }
    //cc("HI")
    for(int i=0;i<connected.size();i++){
        sort(adj[ connected[i] ].begin(), adj[ connected[i] ].end());
    }
    for(int i=0;i<searchList.size();i++){
        u = searchList[i];
        //msg("SEARCH", u)
        found = 0;
        for(int j=0;j<connected.size();j++){
            v = connected[j];
            if( !binary_search(adj[v].begin(),adj[v].end(), u) ){
                found = 1;
                break;
            }
        }
        if(found == 0){
            counter++;
        }

        connected.push_back(u);
    }


    cout << counter << endl;
    return 0;
}
