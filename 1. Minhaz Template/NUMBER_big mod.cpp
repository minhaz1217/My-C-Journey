#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    cout << bigMod(2,20,3) << endl;
    return 0;
}
