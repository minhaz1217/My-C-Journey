/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 28 / June / 2021
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k=0;
        int l=0,r=0;
        int curr = k;
        int sum = 0, mx = 0;
        while(r<nums.size() && l <= r){
            //msg4(l,r,curr, sum, mx)
            if(nums[r] == 1){
                r++;
                sum += 1;
                mx = max(mx, sum);
            }else{ /// right is 0, so we either push left to +1, or we take this and decrease value of curr;
                if(curr >= 1){
                    curr--;
                    sum += 1;
                    mx = max(mx, sum);
                    r++;
                }else{ /// curr is 0, so we keep reducing the value of l
                    if(nums[l] == 0){
                        if(curr+1 <= k){
                            curr++;
                            sum--;
                        }else{
                            r++;
                        }
                    }else{ /// l is on 1, so we reduce sum;
                        sum--;
                    }
                    l++;
                }
            }
        }
        return mx;

    }
};

int main(){

    return 0;
}
