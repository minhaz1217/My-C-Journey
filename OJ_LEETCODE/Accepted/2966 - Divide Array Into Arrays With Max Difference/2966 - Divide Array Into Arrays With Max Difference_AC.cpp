/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Divide array into arrays with max difference
Problem Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference
Complexity: O(n)
Date : 02 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> outputs;
        if(nums.size()%3 != 0){
            return outputs;
        }
        bool error = false;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size() && !error;i+=3){
            vector<int> elements;
            for(int j=0;j<3 && i+j<nums.size() && !error;j++){
                elements.push_back(nums[i+j]);
            }
            if(elements[2] - elements[0] > k){
                error = true;
                break;
            }
            outputs.push_back(elements);
        }

        if(error){
            vector<vector<int>> output;
            return output;
        }
        return outputs;
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
    int t1[] = {15,13,12,13,12,14,12,2,3,13,12,14,14,13,5,12,12,2,13,2,2};
    int k1 = 2;
    vector<int> tc1 = makeVectorFromArray(t1, sizeof(t1));

    
    int t2[] = {1,3,4,8,7,9,3,5,1};
    int k2 = 2;
    vector<int> tc2 = makeVectorFromArray(t2, sizeof(t2));

    // execution
    Solution s;
    vector<vector<int>> output1 = s.divideArray(tc1, k1);
    vector<vector<int>> output2 = s.divideArray(tc2, k2);

    // assert
    vector<vector<int>> eo1;
    vector<vector<int>> eo2({{1,1,3},{3,4,5},{7,8,9}}) ;
    string passed1 = matchVectors(output1, eo1) ? "passed" : "failed";
    string passed2 = matchVectors(output2, eo2) ? "passed" : "failed";
    cout << "Passed?: " << passed1 << " " << passed2 << endl;
    return 0;
}