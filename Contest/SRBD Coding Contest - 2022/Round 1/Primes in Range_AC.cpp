/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/primes-in-range
Complexity:
Date : 16 / Aug / 2022

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
    _INIT;
    sieve();
    mark[1] = 1;
    int tc,a,b,counter;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        counter = 0;
        for(int i=a;i<=b;i++){
            if(mark[i]==0){
                counter++;
            }
        }
        cout << counter << endl;
    }


    return 0;
}
