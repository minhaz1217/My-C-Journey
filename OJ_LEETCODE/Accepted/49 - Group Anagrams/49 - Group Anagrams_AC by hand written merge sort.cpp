/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Group Anagrams
Problem Link: https://leetcode.com/problems/group-anagrams
Complexity: O(nklogk)
Date : 06 / Feb / 2024

Comment: Here I attempt to solve it using merge sort, I've written this merge sort by hand without a template/online guide
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string mergeSort(string strs, int l, int r){
        if(l >= r){
            return string(1, strs[l]);
        }
        string leftList, rightList, mainList;
        int mid = l + (r-l)/2, lPos = 0, rPos= 0;
        leftList = mergeSort(strs, l, mid);
        rightList = mergeSort(strs, mid+1, r);
        while(lPos < leftList.size() || rPos < rightList.size()){
            if(lPos >= leftList.size()){
                mainList.push_back(rightList[rPos]);
                rPos++;
            }else if(rPos >= rightList.size()){
                mainList.push_back(leftList[lPos]);
                lPos++;
            }else if(leftList[lPos] <= rightList[rPos]){
                mainList.push_back(leftList[lPos]);
                lPos++;
            }else{
                mainList.push_back(rightList[rPos]);
                rPos++;
            }
        }
        return mainList;        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;
        vector<vector<string> > results;
        for(int i=0;i<strs.size();i++){
            string str = mergeSort(strs[i], 0, strs[i].size()-1);

            // sort(str.begin(),str.end());
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
    void printVector(vector<int> vec){
        for(int i=0;i<vec.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << vec[i];
        }
        cout << endl;
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
    // testCases.push_back(TestCase(TestCaseType({"eat","tea","tan","ate","nat","bat"}), 
    //                             ExpectedOutputType({ vector<string>({"bat"}),vector<string>({"eat","tea","ate"}),vector<string>({"tan","nat"})})));
    // testCases.push_back(TestCase(TestCaseType({""}), ExpectedOutputType({vector<string>({""})})));
    // testCases.push_back(TestCase(TestCaseType({"a"}), ExpectedOutputType({vector<string>({"a"})})));
    testCases.push_back(TestCase(TestCaseType({"and","dan"}), ExpectedOutputType({vector<string>({"a"})})));

    // execution
    Solution s;
    // vector<int> vec({6,5,4,8,6,49,7,1});
    // for(auto it: s.mergeSort(vec, 0, vec.size()-1)){
    //     cout << it << endl;
    // }

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