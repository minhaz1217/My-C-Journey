/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: First Unique Character In a String
Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string
Complexity: O(n)
Date : 05 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> found(28, 0);
        for(auto letter: s){
            found[letter - 'a']++;
        }

        for(int i=0;i<s.size();i++){
            auto letter = s[i];
            if(found[letter - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

class TestCase{
    public:
    string s;
    int expectedOutput;
    TestCase(string _s,int _expectedOutput){
        s = _s;
        expectedOutput = _expectedOutput;
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase("leetcode", 0));
    testCases.push_back(TestCase("loveleetcode", 2));
    testCases.push_back(TestCase("aabb", -1));

    // execution
    Solution s;

    // assert
    bool allPassed = true;
    for(int i=0;i<testCases.size();i++){
        TestCase testCase = testCases[i];
        int result = s.firstUniqChar(testCase.s);
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