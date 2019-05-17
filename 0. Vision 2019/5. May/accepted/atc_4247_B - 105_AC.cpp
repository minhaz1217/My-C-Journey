/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://abc106.contest.atcoder.jp/tasks/abc106_b?lang=en
Date : 17 / May / 2019
Comment: easy divisor
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

    long long int counter, mainCount ,n;
    cin >> n;
    mainCount  =0;
    for(int k=1;k<=n;k++){
        counter = 0;
        for(int i=1;i<=k;i++){
            if(k%i == 0){
                counter++;
            }
        }
        if(counter == 8 && k%2 == 1){
            mainCount++;
            //msg2(counter, k,mainCount)
        }
    }
    cout << mainCount << endl;

    return 0;
}
