/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10394
Date : 26 / February / 2019
Comment: very easy sieve
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

#define SIEVE 20000400
bool mark[SIEVE];
vector<int>prime,vec;
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
    for(int i=1;i<prime.size();i++){
        if(prime[i] == prime[i-1]+2){
            vec.push_back(prime[i-1]);
        }
    }
}

int main(){
    sieve();
    //cc(vec.size())
    int n;
    while(cin >>n){
        printf("(%d, %d)\n",vec[n-1], vec[n-1]+2);
    }

    return 0;
}
