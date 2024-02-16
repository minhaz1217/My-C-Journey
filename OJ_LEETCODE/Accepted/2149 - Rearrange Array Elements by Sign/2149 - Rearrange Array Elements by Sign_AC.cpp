/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Rearrange Array Elements by Sign
Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign
Complexity: 
Date : 15 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= 0){
                positive.push_back(nums[i]);
            }else{
                negative.push_back(nums[i]);
            }
        }

        vector<int> results;
        int positiveIndex = 0, negativeIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
                if(positiveIndex < positive.size()){
                    results.push_back(positive[positiveIndex]);
                    positiveIndex++;
                }else{
                    results.push_back(negative[negativeIndex]);
                    negativeIndex++;
                }
            }else{
                if(negativeIndex < negative.size()){
                    results.push_back(negative[negativeIndex]);
                    negativeIndex++;
                }else{
                    results.push_back(positive[positiveIndex]);
                    positiveIndex++;
                }
            }
        }
        return results;
    }
};

typedef vector<int> TestCaseType;
typedef vector<int> ExpectedOutputType;
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
        return solution.rearrangeArray(testCase);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase({3,1,-2,-5,2,-4}, {3,-2,1,-5,2,-4}));
    testCases.push_back(TestCase({-1,1}, {1,-1}));

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