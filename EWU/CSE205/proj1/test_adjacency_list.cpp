#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    int i,j,a,b,flag;
    vector<int>graph[6];
    vector<int> visited, path;
    queue<vector<int> > q;
    int src = 2, dest = 5;
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(2);
    graph[5].push_back(4);





	return 0;
}
