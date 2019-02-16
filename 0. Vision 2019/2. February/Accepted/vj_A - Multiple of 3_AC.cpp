/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/283774#problem/A
https://www.codechef.com/problems/MULTHREE
Date : 16 / February / 2019
Comment: There is a pattern try to find it.
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

int main()
{
    long long int tc,k,d0,d1,sum,m1,m2,m3,mySum, myK,m4;
    cin >> tc;
    while(tc--){
            sum = 0;
        cin >> k >> d0 >> d1;
        sum = sum+d0+d1;
        sum += sum%10;
        m1 = sum%10;
        sum = sum+m1;
        m2 =sum%10;
        sum += m2;
        m3 = sum%10;
        sum += m3;
        m4 = sum%10;
        //msg3(m1,m2,m3,m4)
        mySum = m1+m2+m3+m4;
        k = k-3;
        myK = k/4;
        sum = 0;
        sum = sum + d0 + d1 + (d0+d1)%10;
        //msg2(sum, myK, k)
        sum += (myK*mySum);

        if(k%4 == 1){
            sum += m1;
        }else if(k%4 == 2){
            sum += m1+m2;
        }else if(k%4 ==3){
            sum += m1+m2+m3;
        }
        //cc(sum)
        if(sum%3 == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        //cout << sum << endl;
    }
    return 0;
}
