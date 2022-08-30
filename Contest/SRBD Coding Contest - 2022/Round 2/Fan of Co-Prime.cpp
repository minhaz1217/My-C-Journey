/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link:
Complexity:
Date : 30 / Aug / 2022

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

#define MOD 1000000007
int bigMod(long long B,long long P,long long M)
{
    // calculates (b^p)%m
	long long R=1;
	while(P>0){
		if(P%2==1){
			R=(R*B)%M;
		}
		P/=2;
		B=(B*B)%M;
	}
	return R;
}

int main(){
    _INIT;
    int tc;
    long long int n,m;
    cin >> tc;
    for(int i=1;i<=tc;i++){
        cin >> m >> n;
        cout << "Case " << i << ": " << ((bigMod(m, n-1, MOD) % MOD) * (m-1)% MOD)%MOD  << endl;
        // m ^ n
        // m ^ (n-1)
    }
    return 0;
}
