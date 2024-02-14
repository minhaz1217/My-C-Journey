/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Find First Palindromic String in the Array
Problem Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
Complexity: 
Date : 14 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string str = words[i];
            reverse(str.begin(), str.end());
            if(str == words[i]){
                return words[i];
            }
        }
        return "";
    }
};

typedef vector<string> TestCaseType;
typedef string ExpectedOutputType;
class TestCase{
    public:
    TestCaseType words;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _words, ExpectedOutputType _expectedOutput){
        words = _words;
        expectedOutput = _expectedOutput;
    }

    ExpectedOutputType Run(){
        Solution solution;
        return solution.firstPalindrome(words);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase({"abc","car","ada","racecar","cool"}, "ada"));
    testCases.push_back(TestCase({"notapalindrome","racecar"}, "racecar"));
    testCases.push_back(TestCase({"def","ghi"}, ""));

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
        if(passed == false){
            cout << " -> Expected: " << testCase.expectedOutput << " Got: " << result;
        }
        cout << endl;
    }
    cout << "All passed: " << (allPassed == true? "YES" : "NO");

    return 0;
}