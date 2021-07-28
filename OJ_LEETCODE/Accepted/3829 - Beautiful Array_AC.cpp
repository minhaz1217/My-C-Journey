/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3829/
Date : 29 / July / 2021
Comment: Tried for about 5 hours, after that needed to read the core concept about solution... but the code is fully mine and from my own solution.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
class Solution {
public:
    vector<int> solve(vector<int> vec){
        if(vec.size() <= 2){
            return vec;
        }
        vector<int> odd, even;
        for(int i=0;i<vec.size();i += 2){
            odd.push_back(vec[i]);
        }
        for(int j=1;j<vec.size();j+=2){
            even.push_back(vec[j]);
        }
        odd = solve(odd);
        even = solve(even);

        for(int i=0;i<even.size();i++){
            odd.push_back(even[i]);
        }
        return odd;
    }
    vector<int> beautifulArray(int n) {
        vector<int> vec;
        vec.clear();
        for(int i=1;i<=n;i++){
            vec.push_back(i);
        }
        return solve(vec);
    }
};

int main(){

    return 0;
}
