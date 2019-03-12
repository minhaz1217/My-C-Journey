
/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 11 / March / 2019
Comment:
*/
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
    int tc,l,r,k,n;
    vector<int>vec;
    cin >> tc;
    n = tc;
    while(tc--){
        cin >> l >> r;
        vec.push_back(r);
    }
    cin >> k;
    cout << n - (lower_bound(vec.begin(), vec.end(), k) - vec.begin()) << endl;
    return 0;
}
