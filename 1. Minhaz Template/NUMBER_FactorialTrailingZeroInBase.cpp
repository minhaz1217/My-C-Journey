/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10061
Date : 26 / October / 2019
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


#define SIEVE 900
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

int factorialFactors(long long int n, long long int p){
    long long int sum = 0;
    while(n){
        sum += n/p;
        n /= p;
    }
    return sum;
}

int factorialTrailingZeroInBase(long long int n , long long int b){
    /// Finds trailing zeros in N!
    long long int ans = INT_MAX,freq, power;
    for(int i=0;i<prime.size();i++){
        if(b%prime[i] == 0){
            freq = 0;
            while(b%prime[i] == 0){
                freq++;
                b/=prime[i];
            }
            power = factorialFactors(n, prime[i]);
            ans = min(ans, power/freq);
        }
    }
    return ans;
}

int main(){
    long long int n,b;
    sieve();
    while(cin >> n >> b){
        cout << (long long int )factorialTrailingZeroInBase(n,b) << " " << (long long int)numberOfDigitsFactorialInBase(n,b) << endl;
    }
    return 0;
}
