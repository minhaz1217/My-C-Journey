/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/
Date : 13 / July / 2021
Comment: basic binary search problem, but i think linear solution will work also...
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
    vector<int> arr;
    int sz;
    bool check(long long int mid){
        if(mid < 0 || mid >= sz){
           return false;
        }
        long long int l = LLONG_MIN, r = LLONG_MIN;
        if(mid > 0){
            l = arr[mid -1];
        }
        if(mid < sz -1){
            r =arr[mid + 1];
        }
        mid = arr[mid];
        return mid > l && mid > r;
    }
    int bs(int l, int r){
        if(l > r){
            return -1;
        }

        if( l == r){
            if(check(l)){
                return l;
            }
            return -1;
        }

        int mid = (l+r)/2;
        if(check(mid)){
            return mid;
        }
        int leftVal = bs(l, mid);
        if(leftVal > -1){
            return leftVal;
        }
        int rightVal = bs(mid+1, r);
        if(rightVal > -1){
            return rightVal;
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        arr = nums;
        sz = nums.size();
        return bs(0, sz-1);
    }
};
int main(){

    return 0;
}
