#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    queue<pair<int, int> > q;
    int tc,a,b,c,n;

    cin>> tc;
    while(tc--){
        cin>>n;
        vector<pair<int , int> > v[n];
        n--;
        while(n--){
            cin >> a >> b >> c;
            v[a].push_back(pair<int,int>(b,c));
            q.push(pair<int, int>(v[0].first(), v[0].second()));
            while(!q.empty()){
                pair<int, int> p;
                p = q.front();
                q.push();



            }




        }
    }



    return 0;
}
