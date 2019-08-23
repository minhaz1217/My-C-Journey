/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 09 / August / 2019
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


int main(){

    string str;
    char st[200];
    long long int n,fish,baitCount,tc =1;
    cin >> n;
    cin.ignore();
    gets(st);
    while(n--){
        fish = 0;
        baitCount = 0;
        while(gets(st)){
            str = st;
            if(strlen(st) == 0){
                break;
            }
            if(str == "fish"){
                if(baitCount >=2){
                    baitCount -=2;
                    fish++;
                }
            }else if(str == "bait"){
                if(baitCount<6){
                    baitCount++;
                }
            }
        }
        if(tc>1){
            cout << endl;
        }
        cout << fish << endl;
        tc++;
    }
    return 0;
}
