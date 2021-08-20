/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / August / 2021
Comment:
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
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.size()+4, 0);
        int sum;
        dp[0] = 1;
        for(int i=0;i<s.size();i++){

            sum = 0;
            if(i > 0){
                if(s[i] == '0' && !(s[i-1] >= '1' && s[i-1]<='2') ){
                    return 0;
                }
                if((s[i] >= '1' && s[i] <= '9' && s[i-1] == '1' ) || (s[i] >= '1' && s[i] <= '6' && s[i-1] == '2' )){
                    if(i < s.size()-1 && s[i+1] != '0'){
                        sum += dp[i-1];
                    }else if(i == s.size()-1){
                        sum += dp[i-1];
                    }
                    // either 10 - 19 or 20-26
                }
            }
            sum += dp[i];
            dp[i+1] = sum;
        }

        return dp[s.size()];
    }
};

int main(){
    string str;
    cin >> str;
    Solution sol;
    cout << "ANSWER: " << sol.numDecodings(str) << endl;
    return 0;
}
