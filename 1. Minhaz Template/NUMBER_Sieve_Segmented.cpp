/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10140
Date : 01 / March / 2019
Comment: was somewhat hard for me for no particular reason.
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

#define SIEVE 1000400
bool segMark[1000040];

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
void segSieve(long long int l, long long int r){
    for(long long int i=l;i<=r;i++){
        segMark[i-l] = false;
    }
    if(l == 1){
        segMark[0] = true;
    }
    long long int root = sqrt(r) + 1;
    for(long long int i=0;prime[i]<=root;i++){
            //cc(i).
        long long int base = (l/prime[i])*prime[i];

        if(base<l){
            base += prime[i];
        }
        if(base == prime[i]){
            base += prime[i];
        }
        for(long long int j=base;j<=r;j = j+prime[i]){
            segMark[j-l] = true;

        }
    }
}
int main(){
    sieve();
    long long int x, y,lastPrime, maxDist, minDist,primesFound,ai,mx1, mx2, mn1,mn2,dist;
    while(scanf("%lld %lld", &x, &y)!= EOF){
        segSieve(x, y);
        //cc("HI")
        for(long long int i = x;i<=y;i++){
            if(segMark[i-x]== false){
                cc(i)
            }
        }
    }
    return 0;
}
