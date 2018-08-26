#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    cin >> n >> m;
    vector<pair<long long int> >mat[n+4];
    mat[1].push_back(make_pair(n,0));
    while(m--){
        cin >> l >> r >> x;
        mat[l].push_back(make_pair(r,x));
    }

    return 0;
}
