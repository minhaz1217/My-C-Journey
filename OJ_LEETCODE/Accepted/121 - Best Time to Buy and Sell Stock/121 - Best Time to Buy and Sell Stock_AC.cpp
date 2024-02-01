/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Best Time to Buy and Sell Stock
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
Complexity: O(n)
Date : 02 / Feb / 2024

Comment: Try to do it from the end.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> vec(prices.size());
        int currentMax = prices[prices.size()-1];
        for (int i = prices.size()-1; i >=0; i--) {
            if(currentMax < prices[i]){
                currentMax = prices[i];
            }
            vec[i] = currentMax - prices[i];
        }
        int maxProfit = 0;
        for(auto profit: vec){
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

bool matchVectors(vector<int> a, vector<int> b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
vector<int> makeVectorFromArray(int *t1, int arraySize){
    vector<int> tc1(t1, t1 + arraySize/sizeof(t1[0]));
    return tc1;
}
void printVector(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        if(i>0){
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    // setup
    int t1[] = {7,1,5,3,6,4};
    vector<int> tc1 = makeVectorFromArray(t1, sizeof(t1));

    // execution
    Solution s;


    int tc1ExpectedOutput = 5;
    int output = s.maxProfit(tc1);
    string passed = tc1ExpectedOutput == output == 1 ? "passed" : "failed";
    cout << "Output: " << output << " Passed?: " << passed << endl;
    return 0;
}