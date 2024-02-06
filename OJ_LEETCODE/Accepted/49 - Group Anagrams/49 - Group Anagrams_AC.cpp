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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;
        vector<vector<string> > results;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            if(mp.find(str) == mp.end()){
                vector<string> vec;
                vec.push_back(strs[i]);
                mp[str] = vec;
            }else{
                mp[str].push_back(strs[i]);
            }
        }

        for(auto mm: mp){
            results.push_back(mm.second);
        }
        return results;
    }
};


typedef vector<string> TestCaseType;
typedef vector<vector<string>> ExpectedOutputType;
class TestCase{
    public:
    TestCaseType strs;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _strs, ExpectedOutputType _expectedOutput){
        strs = _strs;
        expectedOutput = _expectedOutput;
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase(TestCaseType({"eat","tea","tan","ate","nat","bat"}), 
                                ExpectedOutputType({ vector<string>({"bat"}),vector<string>({"eat","tea","ate"}),vector<string>({"tan","nat"})})));
    testCases.push_back(TestCase(TestCaseType({""}), ExpectedOutputType({vector<string>({""})})));
    testCases.push_back(TestCase(TestCaseType({"a"}), ExpectedOutputType({vector<string>({"a"})})));

    // execution
    Solution s;

    // assert
    bool allPassed = true;
    for(int i=0;i<testCases.size();i++){
        TestCase testCase = testCases[i];
        ExpectedOutputType result = s.groupAnagrams(testCase.strs);
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