/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/282946#problem/I
Date : 15 / February / 2019
Comment: 10^(decimal part of log10 of a number represents that numbers leading numbers.)
Help : https://github.com/Kimbbakar/Contest-Resource/blob/master/Number%20Theory/Tutorial/Leading%20and%20Trilling%20Digits.md
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

    long long n,k,i,sum,tc,caseCounter = 1;
    double sum2,l;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        sum =1;
        sum = bigMod(n,k,1000);
        l = k*log10(n);
        l = l-(int)(l);
        sum2 = (double)pow(10.00,(double)l);
        sum2 = (sum2*100.00);
        //check(sum2)

        //cout << "Case "<< caseCounter++ << ": ";
        if(sum2 == floor(sum2)){
            cout << sum2 << "...";
        }else{
            cout << (int)sum2 << "...";
        }


        if(sum==0){
            cout << "000" << endl;
        }else if(sum < 10){
            cout << "00" << sum << endl;
        }else if(sum<100){
            cout << "0" << sum << endl;
        }else{
            cout << sum << endl;
        }


    }

    return 0;
}
