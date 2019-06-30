/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 30 / June / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
long long int bigMod(long long B,long long P,long long M)
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
    long long int tc,b,p;
    cin >> tc;
    while(tc--){
        cin >> b >> p;
        cout<< bigMod(b,p,10) << endl;
    }
    return 0;
}
