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
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
            }else{
                mp[nums[i]]++;
            }
        }

        int highestCount=-mp[nums[0]], highestNumber=nums[0];
        for(int i=0;i<nums.size();i++){
            if(highestCount < mp[nums[i]] ){
                highestCount = mp[nums[i]];
                highestNumber = nums[i];
            }
        }
        return highestNumber;
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
    bool passed = expectedOutput == output;
    cout << "Output: " << output << " Passed?: " << passed << endl;
    return 0;
}