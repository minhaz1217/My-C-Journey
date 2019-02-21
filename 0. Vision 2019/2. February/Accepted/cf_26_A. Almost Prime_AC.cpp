/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/26/problem/A
Date : 22 / February / 2019
Comment: Very easy problem, using only divisors.
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


#define SIEVE 3500
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
    int n,counter,sum,a;
    map<int,int>mp;
    counter = 0;
    cin >> n;
    counter = 0;
    for(int j=2;j<=n;j++){
        a = j;
        //cc(a)
        for(int i=0;i<prime.size() && a!=1;i++){
            while(a%prime[i] == 0){
                    //msg(a,prime[i])
                    if(!mp[prime[i]]){
                        mp[prime[i]] = 1;
                    }
                    a = a/prime[i];

            }
        }
        //msg(j, mp.size())
        if(mp.size() == 2){
            counter++;
        }
        mp.clear();
    }
    cout << counter << endl;

    return 0;
}
