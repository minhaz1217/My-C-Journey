/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-583
Date : 04 / March / 2019
Comment: easy factorization.
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

#define SIEVE 100500
bool mark[SIEVE];
vector<long long int>prime;
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
    sieve();
    long long int n,temp,counter;
    while(1){
        counter = 1;
        cin >> n;
        if(n == 0){
            break;
        }
        temp = n;
        cout << temp << " = ";
        if(n == -1){
            cout << -1 <<endl;
            continue;
        }else if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n<0){
            cout << -1;
            temp = temp*-1;
            n = n*-1;
            counter++;
        }
       // cc("HI")
        for(int i=0;prime[i]*prime[i]<=n+1;i++){
            if(temp%prime[i] == 0){
                while(temp%prime[i] == 0){
                    //vec.push_back(prime[i]);
                    if(counter>1){
                        cout << " x ";
                    }
                    cout << prime[i];
                    counter++;
                    temp  /= prime[i];
                }
            }
        }
        //cc("HI2")
        if(temp>1){
            if(counter>1){
                    cout << " x ";
            }
            cout << temp;
        }
        cout << endl;
    }


    return 0;
}
