/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Minimum Window Substring
Problem Link: https://leetcode.com/problems/minimum-window-substring/
Complexity:
Date : 04 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<int, int> mp;
        int counter = 1, mn=INT_MAX, minLeft = INT_MAX, minRight = INT_MAX;
        for(int i='A';i<='Z';i++){
            mp[i] = counter;
            counter++;
        }
        for(int i='a';i<='z';i++){
            mp[i] = counter;
            counter++;
        }

        vector<int> needToFind(54,0);
        for(int i=0;i<t.size();i++){
            needToFind[ mp[t[i]] ]++;
        }

        vector<int> found(54, 0);
        int foundAll = false, l=-1,r=-1;
        for(int i=0;i<s.size();i++){
            int ch = mp[s[i]];
            if(needToFind[ch] > 0){
                if(l == -1){
                    l = i;
                }
                found[ch]++;
            }
            foundAll = true;
            for(int j=1;j<54;j++){
                if(found[j] < needToFind[j]){
                    foundAll = false;
                    break;
                }
            }
            // cout << s[i] << " " << foundAll  << " " << s[l] << endl;

            if(foundAll == true){
                r = i;
                // we have more than we need, so we can reduce the window
                // cout << s[l] << " " << found[ mp[s[l]] ] << " "  << needToFind[ mp[s[l]] ] << endl;
                while(found[ mp[s[l]] ] > needToFind[ mp[s[l]] ]){
                    int newLeft = l;
                    for(int j=l+1;j<=r;j++){
                        if(needToFind[mp[s[j]]] > 0){
                            newLeft = j;   
                            break;
                        }
                    }
                    found[mp[s[l]]]--;
                    l = newLeft;
                }
                if(l> -1 && r > -1){
                    if(r-l < mn){
                        mn = r-l;
                        minLeft = l;
                        minRight = r;
                    }
                }
            }
        }

        foundAll = true;
        for(int j=1;j<54;j++){
            if(found[j] < needToFind[j]){
                foundAll = false;
                break;
            }
        }

        if(foundAll == false){
            return "";
        }
        if(l > -1 && r > -1){
            return s.substr(minLeft, minRight-minLeft+1);
        }
        return "";
    }
};
class TestCase{
    public:
    string s;
    string t;
    string expectedOutput;
    TestCase(string _s, string _t, string _expectedOutput){
        s = _s;
        t = _t;
        expectedOutput = _expectedOutput;
    }
};

int main(){
    // arrange
    vector<TestCase> testCases;
    testCases.push_back(TestCase("ADOBECODEBANC", "ABC", "BANC"));
    testCases.push_back(TestCase("a", "a", "a"));
    testCases.push_back(TestCase("a", "aa", ""));
    testCases.push_back(TestCase("acbbaca", "aba", "baca"));
    testCases.push_back(TestCase("cabwefgewcwaefgcf", "cae", "cwae"));


    // execution
    Solution s;

    // assert
    for(int i=0;i<testCases.size();i++){
        TestCase testCase = testCases[i];
        string result = s.minWindow(testCase.s, testCase.t);
        string passed = result == testCase.expectedOutput ? "passed" : "failed";
        cout << "TestCase " << i+1 << ": " << passed << endl;
    }

    return 0;
}