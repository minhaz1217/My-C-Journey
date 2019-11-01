/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10061
Date : 26 / October / 2019
Comment:
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



/// Gives number of digits in bases other than base 10, the logic is floor(logb(n) +  logb(n-1) + .... + logb(1) ) + 1
long long int numberOfDigitsFactorialInBase(long long int n, long long int b){

    double sum = 0.0;
    for(int i=1;i<=n;i++){
        sum += ( log10((double)i)/log10(b) );
    }
    return (long long int )(floor((double)sum)+1);
}
int main(){
    long long int n,b;
    while(cin >> n >> b){
        cout << (long long int)numberOfDigitsFactorialInBase(n,b) << endl;
    }
    return 0;
}
