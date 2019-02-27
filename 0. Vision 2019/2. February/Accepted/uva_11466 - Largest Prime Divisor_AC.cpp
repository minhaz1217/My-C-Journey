/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11466
Date : 26 / February / 2019
Comment: was very hard for me for no particular reason.
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

const int N = 10004000;
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
    long long int n,mx,counter,i ;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        if(n<0){
            n = n*-1;
        }
        counter = 0;
        for(i=0;i<prime.size();i++){

            if(n%prime[i] == 0){
                mx = prime[i];
                counter++;
                while(n%prime[i] == 0){
                    n /= prime[i];
                }
            }
        }
        //msg(counter, n)
        if(counter <= 1){
            if(counter == 0){
                cout << -1 << endl;
            }else if(n>=N){
                cout << n << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            if(n>=N){
                cout << n << endl;
            }else{
                cout << mx << endl;
            }
        }
    }
    return 0;
}
