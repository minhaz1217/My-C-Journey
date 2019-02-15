/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/282946#problem/G
Date : 15 / February / 2019
Comment: got WA 3 times, don't know where the problem was, it might be that floor and ceil of k/2 was the problem.
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

long long int p,q;
void calculate(long long int x, long long int k){
    long long int a,b;
    a = floor((double)x/k);
    b = ceil((double)x/k);
    //msg(a,b)
    if(x%k == 0){
        p = floor(k/2.0);
        q = ceil(k/2.0);
        return;
    }
    p = ((k*b) - x)/(b-a);
    q = k-p;
}

int main(){
    long long int tc,x,k;
    cin >> tc;
    while(tc--){
        cin >> x >> k;
        calculate(x,k);
        cout <<p << " "<< q << endl;
    }


    return 0;
}
