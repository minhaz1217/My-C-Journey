/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10140
Date : 01 / March / 2019
Comment: was somewhat hard for me for no particular reason.
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

#define SIEVE 1000400
bool segMark[1000040];

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
    mark[1>>5] = SET(mark[ 1>>5 ] , 1&31); //making 1 not prime.
    for(int i=4;i<=SIEVE;i+=2){mark[i>>5] = SET(mark[ i>>5 ] , i&31);} // making all even numbers not prime
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
int fullCounter =1; //
// 2146483647 2147483647
void segSieve(long long int l, long long int r){
    for(long long int i=l;i<=r;i++){
        segMark[i-l] = false;
    }
    if(l == 1){
        segMark[0] = true;
    }
    long long int root = sqrt(r) + 1;
    for(long long int i=0;prime[i]<=root;i++){
            //cc(i).
        long long int base = (l/prime[i])*prime[i];

        if(base<l){
            base += prime[i];
        }
        if(base == prime[i]){
            base += prime[i];
        }
        for(long long int j=base;j<=r;j = j+prime[i]){
            segMark[j-l] = true;

        }
    }
}
int main(){
    bsieve();
    long long int x, y,lastPrime, maxDist, minDist,primesFound,ai,mx1, mx2, mn1,mn2,dist;
    while(scanf("%lld %lld", &x, &y)!= EOF){
        maxDist = INT_MIN;
        minDist = INT_MAX;
        lastPrime = -1;
        primesFound = 0;

        segSieve(x, y);
        //cc("HI")
        for(long long int i = x;i<=y;i++){
            if(segMark[i-x]== false){
                primesFound++;
                if(lastPrime != -1){
                    dist = i - lastPrime;
                    //msg2("PRIME", i,dist)
                    if(maxDist < dist){
                        mx1 = lastPrime;
                        mx2 = i;
                        maxDist = dist;
                    }
                    if(dist < minDist){
                        mn1 = lastPrime;
                        mn2 = i;
                        minDist = dist;
                    }
                }
                lastPrime = i;
            }
        }
        if(primesFound >=2 ){
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mn1,mn2,mx1,mx2);
        }else{
            printf("There are no adjacent primes.\n");
        }
    }
    return 0;
}
