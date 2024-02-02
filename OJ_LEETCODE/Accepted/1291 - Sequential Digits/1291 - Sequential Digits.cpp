/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Sequential Digits
Problem Link: https://leetcode.com/problems/sequential-digits
Complexity: O(1)
Date : 02 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> results;
        for(int i=1;i<=9;i++){
            int num = i;
            while(num <= high){
                int lastDigit = num % 10;
                int nextDigit = lastDigit + 1;
                if(nextDigit > 9){
                    break;
                }
                long long int nextNum  = num * 10 + nextDigit;
                if(nextNum >= low && nextNum <= high){
                    results.push_back((int)nextNum);
                }
                num = nextNum;
            }
        }
        sort(results.begin(), results.end());
        return results;
    }
};

// returns true if both vectors are same and has same values in same index
bool isEqual(vector<int> a, vector<int> b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
int main(){
    // arrange
    pair<int,int> tc1 = make_pair(100,300);
    pair<int,int> tc2 = make_pair(1000,13000);

    // execution
    Solution s;
    vector<int> output1 = s.sequentialDigits(tc1.first, tc1.second);
    vector<int> output2 = s.sequentialDigits(tc2.first, tc2.second);

    // assert
    vector<int> eo1({123,234});
    vector<int> eo2({1234,2345,3456,4567,5678,6789,12345}) ;
    string passed1 = isEqual(output1, eo1) ? "passed" : "failed";
    string passed2 = isEqual(output2, eo2) ? "passed" : "failed";
    cout << "Passed?: " << passed1 << " " << passed2 << endl;
    return 0;
}