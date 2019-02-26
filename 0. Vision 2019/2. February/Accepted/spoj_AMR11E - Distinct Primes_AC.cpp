/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/SPOJ-AMR11E
Date : 26 / February / 2019
Comment: very easy prime factorizations.
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

#define SIEVE 10000400
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
    int n,counter,tc;
    vector<int>vec;
    for(int l=25;vec.size()<=1002;l++){
        n = l;
        counter = 0;
        for(int i=0;prime[i]<=l;i++){
            if(n%prime[i] == 0){
                counter++;
                while(n%prime[i] == 0){
                    n/=prime[i];
                }
            }
        }
        if(counter>=3){
            vec.push_back(l);
        }
    }
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << vec[n-1] << endl;
    }
    return 0;
}
