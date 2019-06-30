/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/308147#problem/I
Date : 30 / June / 2019
Comment: interesting implementation of SIEVE.
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

#define SIEVE 10000400
long long int mark[SIEVE];
vector<int>prime;

long long int lowP[SIEVE];
void sieve(){
    int root = sqrt(SIEVE)+1;
    for(int i=2;i<root;i++){
        if(mark[i] == 0){
            for(int j=i;i*j<SIEVE;j++){
                if(mark[i*j] == 0){
                    mark[ i*j ] = i;
                }
                //msg(i*j, i)
            }
        }
    }
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            prime.push_back(i);
        }
    }
}
long long int lowPrime(long long int n){
    if(mark[n] == 0){
        return n;
    }else{
        return mark[n];
    }
}
int main(){
    sieve();
    long long int tc,n,prev;
    lowP[0] = 0;
    lowP[1] = 0;
    for(long long int i=2;i<SIEVE;i++){
        lowP[i] = lowP[i-1] + lowPrime(i);
    }
    //cc(lowPrime(123123))
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << lowP[n] << endl;
    }

    return 0;
}
