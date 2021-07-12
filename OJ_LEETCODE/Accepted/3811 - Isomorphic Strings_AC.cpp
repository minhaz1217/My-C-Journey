/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3811/
Date : 12 / July / 2021
Comment: easy problem.
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
    map<char, char> mp, mp1, mp2;
    bool isIsomorphic(string s, string t) {
        mp.clear();
        for(int i=0;i<s.size();i++){

            if(mp.find(s[i]) == mp.end()){
                if( !(mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end() ) ){
                    return false;
                }
                mp[ s[i] ] = t[i];
                mp1[s[i]] = 1;
                mp2[t[i]] = 1;
            }else{
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){

    return 0;
}
