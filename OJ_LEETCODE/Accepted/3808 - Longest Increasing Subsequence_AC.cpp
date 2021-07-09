/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3808/
Date : 09 / July / 2021
Comment: Straight forward nLog(n) LIS.
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
    int lengthOfLIS(vector<int>& a) {

        int n = a.size();
        const int INF = 1e9;
        vector<int> d(n+1, INF);
        d[0] = -INF;

        for (int i = 0; i < n; i++) {
            int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[j-1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (d[i] < INF)
                ans = i;
        }
        return ans;
    }
};

int main(){

    return 0;
}
