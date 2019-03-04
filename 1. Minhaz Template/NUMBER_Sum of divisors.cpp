/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 26 / February / 2019
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

#define SIEVE 1000000
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

unsigned long long int sumOfDivisor(long long int N){
    unsigned long long int i, root, sum , p, s;
    root = sqrt((long long int)N)+1;
    sum =1;
    int counter = 0;
    for(i = 0;prime[i]<root;i++){
        if(N%prime[i] == 0){
            counter++;
            p = 1;
            while(N%prime[i] == 0){
                N = N / prime[i];
                p = p*prime[i];
            }
            p = p*prime[i];
            s = (p-1)/(prime[i]-1);
            sum = sum*s;
        }
    }
    if(N>1){
        sum = sum * (N+1);
    }
    return sum;
}
int main(){
    sieve();
    cc(sumOfDivisor(823543)) /// sod(48) = 124
    cc(sumOfDivisor(49*7)) /// sod(48) = 124
    cc(sumOfDivisor(20)) /// sod(48) = 124
    cc(sumOfDivisor(48)) /// sod(48) = 124
    cc(sumOfDivisor(72)) /// sod(72) = 195

    return 0;
}
