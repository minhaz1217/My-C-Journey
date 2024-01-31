/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://leetcode.com/problems/majority-element/
Complexity: O(n) O(2)
Date : 01 / Feb / 2024

Comment: Trying to solve using Boyer-Moore Majority Voting Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, votes = 0;
        for(int i=0;i<nums.size();i++){
            if(votes == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                votes++;
            }else{
                votes--;
            }
        }
        return candidate;
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