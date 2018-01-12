#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define MX 30000

int main(){
    int tc,nodes,u,v,w,i;
    vector<pair<int, int> >mat[30001];

    cin >> tc;
    while(tc--){
        cin >> nodes;
        for(i=0;i<nodes;i++){
            cin >> u >> v >> w;
            ///mat[min(u,v)] = make_pair(max(u,v), w);
            mat[min(u,v)].push_back(make_pair(max(u,v),w));
        }
        q.push(0);
        while(!q.empty()){

        }


    }

    return 0;
}
