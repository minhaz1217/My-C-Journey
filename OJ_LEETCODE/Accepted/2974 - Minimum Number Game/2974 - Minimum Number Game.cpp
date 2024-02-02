/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Minimum Number Game
Problem Link: https://leetcode.com/problems/minimum-number-game/
Complexity: O(nlogn)
Date : 02 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int> pq;
        vector<int> results;
        for(auto num: nums){
            pq.push(num*-1);
        }

        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
                int alice, bob;
                alice = pq.top();
                pq.pop();
                bob = pq.top();
                pq.pop();
                results.push_back(bob*-1);
                results.push_back(alice*-1);
            }
        }

        return results;
    }
};

bool matchVectors(vector<int> a, vector<int> b){
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

bool matchVectors(vector<vector<int>> a, vector<vector<int>> b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i=0;i<a.size();i++){
        if(a[i].size() != b[i].size()){
            return false;
        }
        for(int j=0;j<a[i].size();j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}
vector<int> makeVectorFromArray(int *t1, int arraySize){
    vector<int> tc1(t1, t1 + arraySize/sizeof(t1[0]));
    return tc1;
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

int main(){
    // arrange
    vector<int> tc1({5,4,2,3});
    vector<int> tc2({2,5});

    // execution
    Solution s;
    vector<int> output1 = s.numberGame(tc1);
    vector<int> output2 = s.numberGame(tc2);

    // assert
    vector<int> eo1({3,2,5,4});
    vector<int> eo2({5,2}) ;
    string passed1 = matchVectors(output1, eo1) ? "passed" : "failed";
    string passed2 = matchVectors(output2, eo2) ? "passed" : "failed";
    cout << "Passed?: " << passed1 << " " << passed2 << endl;
    return 0;
}