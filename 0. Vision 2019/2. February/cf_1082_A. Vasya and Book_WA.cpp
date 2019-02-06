/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: https://codeforces.com/contest/1082/problem/A
Date : 06 / February / 2019
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
    double n,x,y,tc,a,b;
    int d;
    cin >> tc;
    while(tc--){
        cin >> n >> x >> y >> d;
        if( (int)abs(x-y)%d == 0 ){
            cout << ceil(abs(x-y)/d) << endl;
        }else if( (int)(y-1)%d == 0 || (int)(n-y)%d == 0){
            a = ceil((x)/d) + ceil((y-1)/d);
            b = ceil((n-x)/d) + ceil((n-y)/d);
            //msg(a,b)
            cout << (int)ceil(min(a,b)) << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
