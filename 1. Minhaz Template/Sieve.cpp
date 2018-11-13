#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

//SIEVE
#define SIEVE 10000
bitset<SIEVE +5>mark;
vector<int>prime;

void sieve(){
    prime.push_back(2);
    for(int i=3;i<SIEVE;i+=2){
        if(!mark[i])
        prime.push_back(i);
        for(int j=i*i;j<SIEVE;j+=(2*i)){
            mark[j] = 1;
        }
    }
}
int main(){
    sieve();
    cc(prime.size())
    for(int i=0;i<prime.size();i++){
        msg(i,prime[i])
    }
/*
1227 : 9967
1228 : 9973
*/
    return 0;
}
