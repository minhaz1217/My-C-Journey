/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: Yet Another Alice - Bob Game
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-2/challenges/yet-another-alice-bob-game/problem
Complexity:
Date : 31 / Aug / 2022

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

int main(){
    _INIT;

    int a,b,c;
    cin >> a >> b >> c;
    c = c*2;
    if(c > a || c > b){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }
    return 0;
}
