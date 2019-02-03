//https://codeforces.com/contest/1090/problem/A
// kind of a easy problem, was trying too harder logic.
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    _INIT;
    long long int n,m,a,sum,mx,counter,fullMx;
    vector<pair<long long int, pair<long long int, long long int> > >vec;
    cin >> n;
    mx = INT_MIN;
    fullMx = INT_MIN;
    for(int i=0;i<n;i++){
        cin >> m;
        sum = 0;
        counter = 0;
        mx = INT_MIN;
        for(int j=0;j<m;j++){
            cin >> a;
            mx = max(a,mx);
            sum += a;
            counter++;
        }
        //msg2(mx, counter, sum)
        fullMx = max(fullMx, mx);
        vec.push_back(make_pair(mx, make_pair(counter, sum)));
    }
    //sort(vec.begin(),vec.end());
    //reverse(vec.begin(),vec.end());
    mx = fullMx;
    sum = 0;
    //msg(sum ,mx)
    for(int i=0;i<vec.size();i++){
        //msg2(vec[i].first, vec[i].second.first,vec[i].second.second)
        if(vec[i].first < mx){
            sum = sum + abs( (mx-vec[i].first)*vec[i].second.first );
        }
    }
    cout << sum <<endl;
    return 0;
}
