/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://leetcode.com/problems/majority-element/
Complexity: O(nlogn)
Date : 01 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main(){
    Solution s;
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    // input: [2,2,1,1,1,2,2] output: 2
    int expectedOutput = 2;
    int output = s.majorityElement(vec);
    string passed = expectedOutput == output == 1 ? "passed" : "failed";
    cout << "Output: " << output << " Passed?: " << passed << endl;
    return 0;
}