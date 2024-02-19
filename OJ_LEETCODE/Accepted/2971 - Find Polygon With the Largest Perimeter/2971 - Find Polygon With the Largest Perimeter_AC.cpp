/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Find Polygon With the Largest Perimeter
Problem Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter
Complexity: 
Date : 16 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long long int> sums;
        sums.push_back(nums[0]);
        sums.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            sums.push_back(sums[i] + nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] < sums[i]){
                return sums[i+1];
            }
        }
        return -1;
    }
};

typedef vector<int> TestCaseType;
typedef long long ExpectedOutputType;
class TestCase{
    public:
    TestCaseType testCase;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _testCase, ExpectedOutputType _expectedOutput){
        testCase = _testCase;
        expectedOutput = _expectedOutput;
    }

    ExpectedOutputType Run(){
        Solution solution;
        return solution.largestPerimeter(testCase);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase({5,5,5}, 15));
    testCases.push_back(TestCase({1,12,1,2,5,50,3}, 12));
    testCases.push_back(TestCase({5,5,50}, -1));
    testCases.push_back(TestCase({1,12,1,2,5,50,3,7}, 31));

    // execution

    // assert
    bool allPassed = true;
    for(int i=0;i<testCases.size();i++){
        TestCase testCase = testCases[i];
        ExpectedOutputType result = testCase.Run();
        bool passed = result == testCase.expectedOutput;
        if(passed == false){
            allPassed = false;
        }
        string passResult =  passed == true? "passed" : "failed";
        cout << "TestCase " << i+1 << ": " << passResult;
        cout << endl;
    }
    cout << "All passed: " << (allPassed == true? "YES" : "NO");

    return 0;
}