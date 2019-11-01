/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/310684#problem/A
Date : 13 / July / 2019
Comment: just simple eular totient function implement. Had problems with phi(1)
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long int phi(long long int n)
{

    long long int result = n;
    for (long long int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0){
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1){
        result -= result / n;
    }
    return result;
}
int main(){
    long long int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        if(n == 1){
            cout << 0 << endl;
        }else{
            cout << phi(n) << endl;
        }
    }

    return 0;
}
