/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 04 / March / 2019
Comment:
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
#define MOD ((long long int)1000000007)
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
long long int mod(long long int a, long long int m){
    return a%m;
}
long long int bigMod(long long B,long long P,long long M)
{
    // calculates (b^p)%m
	long long R=1;
	while(P>0){
		if(P%2==1){
            R = mod(R*B, M);
			//R=(R*B)%M;
		}
		P/=2;
		B = mod(B*B, M);
		//B=(B*B)%M;
	}
	return R;
}
long long int calc(long long int p, long long int a){
    long long int up = mod( mod( mod( bigMod(p, a+1, MOD), MOD)  - mod( 1, MOD), MOD )+MOD, MOD);
    return (up * bigMod(p-1, MOD-2, MOD));
}
long long int sod(long long int n, long long int m){
    long long int sum = 1,counter = 0,a,temp = n;
    for(int i=0;prime[i]*prime[i] <= temp+1;i++){
        if(n%prime[i] == 0){
            counter = 0;
            while(n%prime[i] == 0){
                counter++;
                n /= prime[i];
            }
            //msg(prime[i], counter)
            counter = counter*m + 1;
            a = calc(prime[i], counter);
            sum =mod( mod(sum ,MOD) * mod(a, MOD), MOD);
            //sum = ((sum%mod) * (a%mod) )%mod;
        }
    }
    if(n>1){
        counter = 1;
        counter = counter*m + 1;
        a = calc(n, counter);
        sum =mod( mod(sum ,MOD) * mod(a, MOD), MOD);
    }
    return sum;

}
int main(){
    sieve();
    long long int tc,n,m, caseCounter =1,counter;
    cin >> tc;
    while(tc--){
        cin >> n>> m;
        cout << "Case " << caseCounter++ << ": " << sod(n,m) << endl;
    }
    return 0;
}
