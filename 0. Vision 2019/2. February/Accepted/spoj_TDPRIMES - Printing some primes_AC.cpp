/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.spoj.com/problems/TDPRIMES/
Date : 21 / February / 2019
Comment: Easy prime, but had to use optimized sieve.
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

const int N = 100000001;
int lp[N+1];
vector<int> pr;
void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int main(){
    sieve();
    //vector<int> prime = pr;
    //cc(prime.size())
    int a = 1;
    while(1){
        if(a<pr.size()){
            cout << pr[a-1] << endl;
        }else{
            break;
        }
        a += 100;
    }

    return 0;
}
