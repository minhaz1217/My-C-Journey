/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.spoj.com/problems/DIVSUM2/en/
Date : 27 / February / 2019
Comment: very hard sod, had to implement the overflow handling.
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


#define SIEVE 199999999

int mark[ (SIEVE/32)+2 ];
vector<int>prime;
bool CHECK(int N, int pos){
    return (bool)( N&(1<<pos) );
}
int SET(int N, int pos){
    return N= (N | (1<<pos));
}
void bsieve(){
    int j, root = sqrt(SIEVE)+1;
    for(int i=3;i<=root;i+=2){
        if(CHECK(mark[i>>5], i&31) == 0){
            for(j=i*i;j<=SIEVE;j+=(i<<1)){
                mark[j>>5] = SET(mark[ j>>5 ] , j&31);
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=SIEVE;i+=2){
        if(CHECK( mark[i>>5] , i&31)==0){
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
    bsieve();
    unsigned long long int tc,n,sod;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        sod = sumOfDivisor(n);
        cout << sod -n << endl;
    }
    return 0;
}
