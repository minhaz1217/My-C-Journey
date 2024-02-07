/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Group Anagrams
Problem Link: https://leetcode.com/problems/group-anagrams
Complexity: O(nklogk)
Date : 06 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> arr(200,0);
        string result = "";
        for(int i=0;i<s.size();i++){
            arr[ (int)s[i] ]++;
        }
        for(int i=0;i<200;i++){
            int maxCount = arr[i], maxChar = (int)i;
            for(int j=0;j<200;j++){
                if(arr[j] > maxCount){
                    maxCount = arr[j];
                    maxChar = (int)j;
                }
            }
            for(int j=0;j<arr[maxChar];j++){
                result.push_back((char)maxChar);
            }
            arr[maxChar] = 0;
        }
        return result;
    }
};


typedef string TestCaseType;
typedef string ExpectedOutputType;
class TestCase{
    public:
    TestCaseType s;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _s, ExpectedOutputType _expectedOutput){
        s = _s;
        expectedOutput = _expectedOutput;
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase("tree", "eert"));
    testCases.push_back(TestCase("cccaaa", "aaaccc"));
    testCases.push_back(TestCase("Aabb", "bbAa"));

    // execution
    Solution s;

    // assert
    bool allPassed = true;
    for(int i=0;i<testCases.size();i++){
        TestCase testCase = testCases[i];
        ExpectedOutputType result = s.frequencySort(testCase.s);
        bool passed = result == testCase.expectedOutput;
        if(passed == false){
            allPassed = false;
        }
        string passResult =  passed == true? "passed" : "failed";
        cout << "TestCase " << i+1 << ": " << passResult << endl;
    }
    cout << "All passed: " << (allPassed == true? "YES" : "NO");

    return 0;
}