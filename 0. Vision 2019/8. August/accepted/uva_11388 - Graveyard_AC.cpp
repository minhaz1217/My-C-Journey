/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-1388
Date : 08 / August / 2019
Comment: somewhat easy problem.
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


int main(){
    double n,m,old,nw,sum,pos,k;
    while(cin >> n >> m){
        old = 10000.0/n;
        nw = 10000.0 / (m+n);
        sum = 0;
        for(int i=0;i<n;i++){
            pos = old*i;
            k = (int)(pos / nw);
            sum+= min( pos - nw*k , nw*(k+1)-pos  );
        }
        printf("%.4f\n", sum);
    }
    return 0;
}
