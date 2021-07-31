/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3833/
Date : 31 / July / 2021
Comment: Leetcode hard, but it was very easy to me... took 20 mins to solve.
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
    int trap(vector<int>& height) {
        int sz = height.size(), LRMax = INT_MIN,RLMax = INT_MIN;
        vector<int> LR(sz, 0), RL(sz, 0);
        for(int i=0,j=sz-1;i<sz;i++,j--){
            LRMax = max( height[i], LRMax );
            RLMax = max( height[j], RLMax );
            LR[i] = LRMax;
            RL[j] = RLMax;
        }
        int counter = 0,mn = INT_MAX;;
        for(int i=0;i<sz;i++){
            mn = min( LR[i], RL[i] );
            if(height[i] < mn){
                counter += mn - height[i];
            }
        }
        return counter;
    }
};
int main(){

    return 0;
}
