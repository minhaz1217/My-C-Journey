/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Least Number of Unique Integers after K Removals
Problem Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
Complexity: 
Date : 16 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int ,int > mp;
        vector<pair<int,int> > vec;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[ arr[i] ] = 1;
            }else{
                mp[arr[i]]++;
            }
        }
        for(auto it=mp.begin(); it!=mp.end();it++){
            vec.push_back(make_pair( it->second, it->first ));
        }
        sort(vec.begin(), vec.end());
        int counter = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first > k){
                counter++;
            }else{
                k = k-vec[i].first;
            }
        }

        return counter;
    }
};

typedef vector<int> TestCaseType;
typedef int TestCaseType2;
typedef int ExpectedOutputType;
class TestCase{
    public:
    TestCaseType testCase;
    TestCaseType2 k;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _testCase, TestCaseType2 _k, ExpectedOutputType _expectedOutput){
        testCase = _testCase;
        k = _k;
        expectedOutput = _expectedOutput;
    }

    ExpectedOutputType Run(){
        Solution solution;
        return solution.findLeastNumOfUniqueInts(testCase, k);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase({5,5,4}, 1, 1));
    testCases.push_back(TestCase({4,3,1,1,3,3,2}, 3, 2));
    testCases.push_back(TestCase({4,3,1,1,3,3,2,5,3,4,6,6,6,4,6,5,8}, 5, 4));
    testCases.push_back(TestCase({4,3,1,1,3,3,2,5,3,4,6,6,6,4,6,5,8}, 10, 2));

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