/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11728
Date : 26 / February / 2019
Comment: easy SOD.
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

#define SIEVE 10000
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

int sumOfDivisor(int N){
    int i, root, sum , p, s,temp = N;
    root = sqrt(N)+1;
    sum =1;
    for(i = 0;prime[i]<root;i++){
        if(N%prime[i] == 0){
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
        p = N*N;
        s = (p-1)/(N-1);
        sum = sum * s;
    }
    return sum;
}
int main(){
    mark[0] = 1;
    sieve();
    int caseCounter =1 , a;
    vector<int>sod(SIEVE+4);
    //cc(sod.size())
    //cc(sod[5])
    //msg(4, sumOfDivisor(25))
    sod[1] =1;
    for(int i=2;i<SIEVE;i++){
        a = sumOfDivisor(i);
        //msg(i,a)
        if(a<SIEVE){
            sod[a] = i;

        }
    }

    while(1){
        cin >> a;
        if(a == 0){
            break;
        }
        cout << "Case " << caseCounter++ << ": ";
        if(sod[a] == 0){
            cout << -1;
        }else{
            cout << sod[a];
        }
        cout << endl;

    }

    return 0;
}
