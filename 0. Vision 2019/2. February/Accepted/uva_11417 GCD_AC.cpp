/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11417
Date : 20 / February / 2019
Comment: Basic euclidean GCD
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
    long long int n,sum;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        sum = 0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                sum += __gcd(i,j);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
