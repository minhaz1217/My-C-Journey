/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3823/
Date : 22 / July / 2021
Comment: easy problem but ranked leetcode medium.
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
    int partitionDisjoint(vector<int>& nums) {
        int mn = nums[ nums.size()-1 ], mx = nums[0];
        int arrMin[30004], arrMax[30004];
        for(int i=0;i<nums.size();i++){
            mx = max(mx, nums[i]);
            arrMax[i] = mx;
        }

        for(int i=nums.size()-1;i>=0;i--){
            mn = min(mn, nums[i]);
            arrMin[i] = mn;
        }

        for(int i=0;i<nums.size()-1;i++){
            if(arrMax[i] <= arrMin[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};

int main(){

    return 0;
}
