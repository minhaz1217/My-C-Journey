/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / February / 2019
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
    long long int tc,n,a,b,sum1,sum2;
    cin >> tc;
    while(tc--){
        cin >> n >> a >> b;
        if(n == 1){
            sum1 = a;
        }else {
            sum1 = min(n*a, (long long int)((n%2)*a + floor(n/2.0)*b) );
        }
        cout << sum1 << endl;
    }
    return 0;
}
