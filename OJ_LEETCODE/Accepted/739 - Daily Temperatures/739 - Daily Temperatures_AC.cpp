/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name: Daily Temperatures
Problem Link: https://leetcode.com/problems/daily-temperatures/description/
Complexity:
Date : 01 / Feb / 2024

Comment: n is large but unique numbers are total 70 so don't calculate one number multiple times. Solution looks like n2 but not n2 in execution.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysToWait(temperatures.size(), -1);
        vector<int> similar;
        for(int i=0;i<temperatures.size();i++){
            if(daysToWait[i] == -1){
                similar.push_back(i);
                for(int j=i+1;j<temperatures.size();j++){
                    if(temperatures[j] > temperatures[i]){
                        if(similar.size()>0){
                            for(int k=0;k<similar.size();k++){
                                daysToWait[similar[k]] = j-similar[k];
                            }
                            cout << endl;
                            similar.clear();
                        }
                        break;
                    }else if(temperatures[j] == temperatures[i]){
                        similar.push_back(j);
                    }
                }
                for(int k=0;k<similar.size();k++){
                    daysToWait[similar[k]] = 0;
                }
                similar.clear();
                
            }
        }
        for(int i=0;i<daysToWait.size();i++){
            if(daysToWait[i] == -1){
                daysToWait[i] = 0;
            }
        }
        return daysToWait;
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
    int t1[] = {73,74,75,71,69,72,76,73};
    vector<int> tc1 = makeVectorFromArray(t1, sizeof(t1));

    // execution
    Solution s;
    vector<int> output = s.dailyTemperatures(tc1);

    // assert
    int t1EOArr[] = {1,1,4,2,1,1,0,0};
    vector<int> tc1EO = makeVectorFromArray(t1EOArr, sizeof(t1EOArr));
    string passed = matchVectors(output, tc1EO) ? "passed" : "failed";
    cout << "Passed?: " << passed << endl;
    return 0;
}