#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 100004
vector<int>vec,beauty,dep,nods;
vector<int>mat[MX];

void dfs(int n){
    sum = 0;
    for(i=0;i<mat[n].size();i++){
        u = mat[n][i];
        dfs(u);
    }

}

int main(){

    cin >> n;
    vec.push_back(-1);
    for(i=1;i<=n;i++){
        cin >> a;
        vec.push_back(a);
    }
    for(i=0;i<=n;i++){
        beauty.push_back(0);
        dep.push_back(0);
        nods.push_back(0);
    }

    dep[1]= 1;
    beauty[1] = vec[1];
    for(i=2;i<=n;i++){
        cin >> a;
        mat[i].push_back(a);
        mat[a].push_back(i);
        dep[i] = dep[a]+1;
        nods[dep[i]]++;
        beauty[dep[i]] = max(beauty[i], vec[i]);
    }



    return 0;
}
