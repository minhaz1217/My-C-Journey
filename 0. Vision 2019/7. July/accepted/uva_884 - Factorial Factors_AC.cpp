/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/310684#problem/D
Date : 13 / July / 2019
Comment: easy prime solution, needs to update some loop inside for better time.
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


#define SIEVE 1000040
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
int factors[SIEVE];
int main(){
    sieve();
    long long int n,temp, counter;
    factors[1] = 0;
    mark[1] = 1;
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            factors[i] = factors[i-1]+1;
        }else{
            temp = i;
            counter = 0;
            for(int j=0;prime[j]<=temp;j++){
                while(temp%prime[j] == 0){
                    counter++;
                    temp= temp/prime[j];
                }
                if(mark[temp] == 0){
                    counter++;
                    break;
                }
            }
            factors[i] = factors[i-1]+counter;
        }

//            msg(i, factors[i])
    }

    while(cin >> n){
        cout << factors[n] << endl;
    }


    return 0;
}
