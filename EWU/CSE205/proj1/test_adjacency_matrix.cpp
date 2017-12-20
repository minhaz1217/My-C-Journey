#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    vector<int> graph[5];
    graph[0].push_back(0);
    graph[0].push_back(1);
    graph[0].push_back(0);
    graph[0].push_back(1);
    graph[0].push_back(1);

    graph[1].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(1);
    graph[1].push_back(1);
    graph[1].push_back(1);

    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(0);
    graph[2].push_back(0);
    graph[2].push_back(1);

    graph[3].push_back(1);
    graph[3].push_back(1);
    graph[3].push_back(0);
    graph[3].push_back(0);
    graph[3].push_back(1);

    graph[4].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(1);
    graph[4].push_back(0);




	return 0;
}
