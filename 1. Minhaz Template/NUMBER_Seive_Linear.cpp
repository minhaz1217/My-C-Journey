/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / February / 2019
Comment:
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

const int N = 100000;
int lp[N+1];
vector<int> prime;
void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back (i);
        }
        for (int j=0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}

int main(){
    sieve();
    for(int i=0;i<10;i++){
        msg(i, prime[i])
    }
    return 0;
}
