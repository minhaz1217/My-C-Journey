/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-686
Date : 20 / February / 2019
Comment: Easy problem
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

#define SIEVE 36768
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
    mark[1] = 1;
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            prime.push_back(i);
        }
    }
}

int main(){
    int n,l,r,counter;
    sieve();
    while(1){
        cin >> n;
        if(n ==0){
            break;
        }
        counter = 0;
        for(int i=0;i<prime.size();i++){
            //cc(i)
            if(prime[i]>n){
                break;
            }
            if(mark[n-prime[i]] == 0 ){
                if(!(prime[i] > n-prime[i])){
                    counter++;
                }
            }

        }
        cout << counter << endl;
    }
    return 0;
}
