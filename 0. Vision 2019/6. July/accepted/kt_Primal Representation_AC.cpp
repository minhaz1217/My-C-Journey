/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 30 / June / 2019
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


#define SIEVE 1004000
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
    sieve();
    long long int n,printed= 0,curr, counter;

    while(cin >> n){
        printed = 0;
        map<int,int>mp;
        if(n < 0){
            n*=-1;
            mp[-1] = 1;
        }
        for(int i=0;i<prime.size();i++){
            if(n%prime[i] == 0){
                mp[prime[i]] = 1;
                n /= prime[i];
            }
            while(n%prime[i] == 0){
                n/=prime[i];
                mp[ prime[i]]++;
            }

            if(n == 1){
                break;
            }
            if(prime[i] >= sqrt(n)){
                mp[n] = 1;
                n = 1;
                break;
            }
        }
        if(n!= 1){
            mp[n] = 1;
        }

        for(map<int,int>::iterator it= mp.begin();it!=mp.end();it++){
            if(it!= mp.begin()){
                cout << " ";
            }
            if(it->second > 1){
                cout << it->first << "^" << it->second;
            }else{
                cout << it->first;
            }
        }
        cout << endl;
    }
    return 0;
}
