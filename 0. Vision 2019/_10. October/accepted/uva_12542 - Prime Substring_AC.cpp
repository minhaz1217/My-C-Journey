/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-12542
Date : 28 / October / 2019
Comment: was some problem where mx was getting set without the if triggering.
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


#define SIEVE 100004
bool mark[SIEVE];
vector<int>prime;
void sieve(){
    int root = sqrt(SIEVE)+1;
    for(int i=2;i<root;i++){
        if(mark[i] == 0){
            for(int j=i;i*j<SIEVE;j++){
                mark[i*j] = 1;
            }
        }
    }
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            prime.push_back(i);
        }
    }
}
int main(){

    string str,temp;
    long long int a,mx;
    map<string,int>mp;
    sieve();
    while(1){
        cin >> str;
        if(str == "0"){
            break;
        }
        mx = -1;
        for(int l=6;l>=1;l--){
            for(int i=0;i+l < str.size();i++){
                temp = str.substr(i,l);
                stringstream ss(temp);
                ss >> a;
                if(a <SIEVE){
                    if(mark[a] == 0){
                        mx = max(mx, a);
                    }
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}
