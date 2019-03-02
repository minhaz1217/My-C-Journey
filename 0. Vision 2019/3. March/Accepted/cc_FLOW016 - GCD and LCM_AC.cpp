/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.codechef.com/problems/FLOW016
Date : 02 / March / 2019
Comment: Easy gcd and lcm, solving it for the heck of it.
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

    long long int tc,a,b,g;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        g = __gcd(a,b);
        cout << g << " "<< a*b/g << endl;
    }

    return 0;
}
