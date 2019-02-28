/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-294
Date : 27 / February / 2019
Comment: very easy NOD.
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

long long int nod(long long int N){
    long long int i, root, sum , p, s,counter;
    root = sqrt((long long int)N)+1;
    sum =1;
    for(i = 0;prime[i]<root;i++){
        if(N%prime[i] == 0){
            counter = 1;
            while(N%prime[i] == 0){
                N = N / prime[i];
                counter++;
            }
            sum = sum*counter;
        }
    }
    if(N>1){
        sum = sum * 2;
    }
    return sum;
}
int main(){
    sieve();
    long long int tc,l,r,temp, mx,pos;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &l, &r);
        mx = INT_MIN;
        for(long long int i = l;i<=r;i++){
            temp = nod(i);
            if(temp > mx){
                mx = temp;
                pos = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, r, pos , mx);
    }

    return 0;
}
