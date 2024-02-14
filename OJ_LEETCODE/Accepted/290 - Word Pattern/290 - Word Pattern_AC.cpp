/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Word Pattern
Problem Link: https://leetcode.com/problems/word-pattern/
Complexity: 
Date : 12 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        map<char, string> mp;
        map<string, int> found;
        string str;
        for(int i=0;i<pattern.size();i++){
            ss >> str;
            if(mp.find(pattern[i]) == mp.end()){
                if(found.find(str) == found.end()){
                    mp[pattern[i]] = str;
                    found[str] = 1;
                }else{
                    return false;
                }
            }else{
                if(mp[pattern[i]] != str){
                    return false;
                }
            }
        }
        if(ss >> str){
            return false;
        }
        return true;
    }
};

typedef string TestCaseType;
typedef string TestCaseType2;
typedef bool ExpectedOutputType;
class TestCase{
    public:
    TestCaseType pattern;
    TestCaseType2 s;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _pattern, TestCaseType2 _s, ExpectedOutputType _expectedOutput){
        pattern = _pattern;
        s = _s;
        expectedOutput = _expectedOutput;
    }

    ExpectedOutputType Run(){
        Solution solution;
        return solution.wordPattern(pattern, s);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase("abba","dog cat cat dog", true));
    testCases.push_back(TestCase("abba","dog cat cat fish", false));
    testCases.push_back(TestCase("aaaa","dog cat cat dog", false));
    testCases.push_back(TestCase("abba","dog dog dog dog", false));

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