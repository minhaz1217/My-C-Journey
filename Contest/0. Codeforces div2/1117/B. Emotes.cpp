/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 18 / February / 2019
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
    long long int n,m,k,sum = 0, div,big1,big2,a;
    vector<long long int >vec;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    big1 = vec[vec.size()-1];
    big2 = vec[vec.size()-2];
    div = floor((double)m / (k+1));
    sum = div * ( k*big1 + big2);
    sum +=  (m % (k+1))*big1;
    cout << sum << endl;
    return 0;
}
