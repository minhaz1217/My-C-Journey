/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Perfect Squares
Problem Link: https://leetcode.com/problems/perfect-squares/
Complexity: 
Date : 07 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> vec;
    map<int, int> dp;

public:
    int findMinimum(int n, int startingPosition) {
        // cout << "Entered: " << n << endl;
        if (n <= 3) {
            return n;
        }

        if (n < 0 || startingPosition < 0 || startingPosition >= vec.size()) {
            return 999;
        }

        if (dp[n]) {
            return dp[n];
        }

        int sq = sqrt(n);
        if(sq * sq == n){
            dp[n] = 1;
            return 1;
        }
        
        int totalNeeded = 0, minimumTotalNeeded = INT_MAX;
        for (int i = min(startingPosition+3, (int)vec.size()-1); i >= 0; i--) {
            if (vec[i] == n) {
                minimumTotalNeeded = min(minimumTotalNeeded, 1);
                break;
            }
            if (n >= vec[i]) {
                // cout << "FOUND: " << " N " << n << " " << vec[i] << " " << n - vec[i] << endl;
                totalNeeded =  1 + findMinimum(n - vec[i], i);
                // cout <<"FOR " << n << " " << totalNeeded << endl;
                minimumTotalNeeded = min(minimumTotalNeeded, totalNeeded);
            }
        }

        dp[n] = minimumTotalNeeded;
        // cout << "MIN: " << n << " " << dp[n] << endl;
        return minimumTotalNeeded;
    }
    int numSquares(int num) {
        dp[1] = 1;
        for (int i = 1; i * i <= num; i++) {
            for(int j=1;j<=2;j++){
                dp[i*i*j] = j;
            }
            vec.push_back(i * i);
        }
        return findMinimum(num, vec.size() - 1);
    }
};

typedef int TestCaseType;
typedef int ExpectedOutputType;
class TestCase{
    public:
    TestCaseType s;
    ExpectedOutputType expectedOutput;
    TestCase(TestCaseType _s, ExpectedOutputType _expectedOutput){
        s = _s;
        expectedOutput = _expectedOutput;
    }

    ExpectedOutputType Run(){
        Solution solution;
        return solution.numSquares(s);
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase(12,3));
    testCases.push_back(TestCase(13,2));
    testCases.push_back(TestCase(22,3));
    testCases.push_back(TestCase(7168,4));
    testCases.push_back(TestCase(5,2));
    testCases.push_back(TestCase(20,2));
    testCases.push_back(TestCase(367,4));
    testCases.push_back(TestCase(380,4));
    testCases.push_back(TestCase(378,3));

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