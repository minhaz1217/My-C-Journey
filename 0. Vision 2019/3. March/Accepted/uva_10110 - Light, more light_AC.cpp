/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10110
Date : 27 / March / 2019
Comment: somewhat easy problem.
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


#define SIEVE 10000000
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
int isPrime(long long int n){
    if(n<SIEVE){
        return mark[n];
    }
    int root = sqrt(n)+1;
    for(int i=0;prime[i]<root;i++){
        if(n%prime[i] == 0){
            return 1;
        }
    }
    return 0;
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
    //cc((long long int)(1<<31))
    sieve();
    long long int n,ans;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        ans = isPrime(n);
        if(ans == 0){
            cout << "no" << endl;
        }else{
            ans = nod(n);
            if(ans%2 == 0){
                cout << "no" << endl;
            }else{
                cout << "yes" << endl;
            }
        }
    }


    return 0;
}
