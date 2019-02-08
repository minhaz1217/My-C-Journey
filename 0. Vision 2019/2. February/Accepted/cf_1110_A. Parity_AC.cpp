/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: https://codeforces.com/contest/1110/problem/A
Date : 08 / February / 2019
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


int main()
{
    long long int a,n,k,sum =0;
    cin >> n >> k;
    for(int i=0; i<k; i++)
    {
        cin >> a;
        if(a%2 != 0)
        {
            sum += a;
        }
    }

    if(n%2 == 0)
    {
        if(a %2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }
    else
    {
        if(sum%2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }

    return 0;
}
