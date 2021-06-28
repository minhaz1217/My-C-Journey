/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/
Date : 28 / June / 2021
Comment: took me 1.15 hour, at first was going for recursive, then was going for two pointer, then realized stack is better.
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

    string removeDuplicates(string s) {
        if(s.size() <=1){
            return s;
        }

        int l =0, r = 1;
        stack<char> st;
        string result = "";
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if( st.size() > 0 && s[i] == st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main(){
    string input;
    cin >> input;
    Solution solution;
    cout << solution.removeDuplicates(input) << endl;
    return 0;
}
