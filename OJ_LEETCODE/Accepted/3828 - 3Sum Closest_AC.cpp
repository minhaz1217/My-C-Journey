/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3828/
Date : 27 / July / 2021
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

    int bs(vector<int> &nums, int l, int r, int target){

        int mid;
        while(l<r){
            //cout << l << " " << r << endl;
            mid = (l+r)/2; // r + (r-l)/2
            if( abs(target - nums[mid]) <= abs(target - nums[mid+1])){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if( abs(target - nums[l]) < abs(target - nums[r])){
            return nums[l];
        }else{
            return nums[r];
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int mn = INT_MAX, result;
        for(int i=0;i<sz-2;i++){
            for(int j=i+1;j<sz-1;j++){
                int numberToFind = target - nums[i] - nums[j];
                int bsNumber = bs(nums, j+1, sz-1,numberToFind );

                if(mn >= abs( target - (bsNumber + nums[i] + nums[j]) )){
                    mn = abs( target - (bsNumber + nums[i] + nums[j]) );
                    result = nums[i] + nums[j] + bsNumber;
                }

            }
        }
        return result;
    }
};

int main(){

    return 0;
}
