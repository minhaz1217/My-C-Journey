/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/282946#problem/B
Date : 10 / February / 2019
Comment: very basic extended euclidean problem.
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

long long int Extended_Euclidean(long long int a,long long int b, long long int &x,long long int &y){
    // returns Ax + By = D ( where D = gcd(a,b))
    // 2250 x 1 + 360 x -6 = 90
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=Extended_Euclidean(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
}

int main(){
    long long int a,b,d,x,y;
    while(cin >> a  >> b){
        d = Extended_Euclidean(a,b,x,y);
        cout << x << " " << y << " " << d << endl;
    }

    return 0;
}
