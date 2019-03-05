/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 05 / March / 2019
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
    long long int n,a,sum,q;
    vector<long long int>vec,vec2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    sum = 0;
    vec2.push_back(0);
    for(int i=0;i<n;i++){
        sum += vec[i];
        vec2.push_back(sum);
        //vec2.push_back( vec2[i-1]+vec[i] );
    }
    /*
    for(int i=0;i<n;i++){
        cout << vec2[i] << " ";
    }
    cout << endl;
    */
    cin >> q;
    while(q--){
        cin >> a;
        cout << (long long int)(vec2[n] - vec2[n-a+1] + vec2[n-a])<< endl;
    }


    return 0;
}
