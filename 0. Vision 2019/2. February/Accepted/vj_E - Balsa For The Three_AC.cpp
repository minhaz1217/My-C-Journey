/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/CodeChef-BFTT
https://www.codechef.com/problems/BFTT
Date : 16 / February / 2019
Comment: Easy problem, just brute force
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

long long int count3(long long int n){

    long long int counter = 0;
    while(n!=0){
        if(n%10 == 3){
            counter++;
        }
        n = n/10;
    }
    return counter;
}
int main()
{
    long long int tc,a,counter;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        stringstream ss(str);
        ss >> a;
        for(long long int i=a+1;;i++){
            if(count3(i) >=3){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
