/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-406
Date : 19 / February / 2019
Comment: very very easy problem, mistook the sieve range
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

#define SIEVE 1500
bitset<SIEVE +5>mark;
vector<int>prime;
void sieve(){
    prime.push_back(1);
    prime.push_back(2);
    for(int i=3;i<SIEVE;i+=2){
        if(!mark[i]){
            prime.push_back(i);
            for(int j=i*i;j<SIEVE;j+=(2*i)){
                mark[j] = 1;
            }
        }
    }
}
int main(){
    sieve();
    int n,c,pos,l,r,sz;

    while(cin >> n >> c){
        pos = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
        if(prime[pos] > n){
            pos--;
        }
        sz = pos+1;
        if(sz %2 == 0){
            if(sz <= 2*c){
                l = 0;
                r = sz;
            }else{
                l = (sz-2*c)/2;
                r = l+ 2*c;
            }
        }else{
            if(sz<= 2*c - 1){
                for(int i=0;i<sz;i++){
                    l = 0;
                    r = sz;
                }
            }else{
                l = (sz-(2*c-1))/2;
                r = l+ (2*c-1);
                if(2*c -1 == 0){
                    r = -1;
                }
            }
        }
        cout << n << " "<< c << ":";
        if(r == -1){
            cout << endl;
        }else{
            for(int i=l;i<r;i++){
                cout << " " << prime[i];
            }
            cout << endl;
        }
        cout << endl;
    }



    return 0;
}
