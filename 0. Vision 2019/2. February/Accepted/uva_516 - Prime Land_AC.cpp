/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-516
Date : 27 / February / 2019
Comment: hard to read and understand question, also last input is wrong.
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

#define SIEVE 100400
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
    sieve();
    string str;
    long long int n,sum,a,b,counter,printedOnce;
    while(1){
        getline(cin, str);
        if(str.size()==1){
            break;
        }
        sum = 1;
        stringstream ss(str);
        while(ss>>a>>b){
            sum = sum * (pow(a,b));
        }
        counter = 0;
        //msg("SUM", sum)
        sum = sum -1;
        printedOnce = 0;
        for(int i = prime.size()-1;i>=0;i--){
            if(sum%prime[i] == 0 && prime[i]<=sum){
                counter = 0;
                while(sum%prime[i] == 0){
                    sum = sum /prime[i];
                    counter++;
                }
                if(printedOnce >0){
                    cout << " ";
                }
                cout << prime[i] << " " << counter;
                printedOnce++;

            }
        }
        cout << endl;
    }

    return 0;
}
