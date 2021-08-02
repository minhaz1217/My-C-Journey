/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3836/
Date : 02 / August / 2021
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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            vec.push_back(make_pair(nums[i],i));
        }
        sort(vec.begin(), vec.end());
        for(int i=0;i<vec.size()-1;i++){
            int remaining = lower_bound(vec.begin() + i+1, vec.end(), make_pair(target - vec[i].first,0)) - vec.begin();
            if(remaining >= 0 && remaining < vec.size()){
                if(vec[i].first + vec[remaining].first == target){
                    result.push_back( vec[i].second );
                    result.push_back( vec[remaining].second );
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){

    return 0;
}
