/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 191. Number of 1 Bits
Problem Link: https://leetcode.com/problems/number-of-1-bits/
Complexity: O(32)
Date : 10 / Jul / 2022

Comment: One line solution using the __builtin_popcount
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

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main(){
    _INIT;

    return 0;
}
