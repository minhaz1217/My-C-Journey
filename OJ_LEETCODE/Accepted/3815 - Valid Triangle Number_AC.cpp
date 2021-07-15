/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3815/
Date : 15 / July / 2021
Comment: normal binary search.
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
    int triangleNumber(vector<int>& nums) {
        int count = 0, sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<sz-1;i++){
            for(int j=i+1;j<sz;j++){
                int pos = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]) - nums.begin();
                pos--;
                if(pos >= 0 && pos < sz){
                    count += max(0, pos-j);
                }
            }
        }
        return count;
    }
};
int main(){

    return 0;
}
