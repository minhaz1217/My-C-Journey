/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 26 / February / 2019
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

long long int bigMod(long long int B,long long int P,long long int M)
{
    // calculates (b^p)%m
	long long int R=1;
	while(P>0){
		if(P%2==1){
			R=(R*B)%M;
		}
		P/=2;
		B=(B*B)%M;
	}
	return R;
}
bool millerTest(long long int n, long long int d){
    long long int a = 2 + rand()%(n-4);
    long long int x = bigMod(a,d,n);
    if(x == 1 || x == n-1){
        return true;
    }
    while(d!= n-1){
        x = (x*x)%n;
        d = d*2;
        if(x == 1){
            return false;
        }
        if(x == n-1){
            return true;
        }
    }
}
bool isPrime(long long int n, int k=4){
    if(n == 2 || n == 3){
        return true;
    }else if(n<=1 || n%2 ==0){
        return false;
    }
    long long int d = n-1; // we generate a d such that n -1 = 2^d * r
    while(d%2 == 0){
        d = d/2;
    }
    for(int i=0;i<k;i++){
        if(!millerTest(n, d)){
            msg2(i, n, d)
            return false;
        }
    }
    return true;

}

int main(){
    cc(isPrime(13))
    cc(isPrime(101))
    cc(isPrime(2146483813,4))
    cc(isPrime(2146841273,4))

    return 0;
}
