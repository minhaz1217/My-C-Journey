#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,k,a,b,u,w,cost;
    cin >> n >> k >> a >> b;
    map<long long int, long long int>mp;
    queue<pair<long long int, long long int> >q;
    q.push(make_pair(1,0));
    mp[1] = 1;
    cost = INT_MAX;
    while(!q.empty()){
        u = q.front().first;
        w = q.front().second;
        q.pop();
        if(u == n){
            //msg(u, w)
            cost =min(cost,w);
        }else if(u >n){
        continue;
        }
        if(n%u == 0){
            cost = min(cost, w+ n/k * b);
        }
        if(u+1 <=n){

            q.push(make_pair(u+1, w+a));
        }
    }
    cout << cost << endl;



    return 0;
}
