/*
Minhazul Hayat Khan
https://minhazul.com
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://leetcode.com/problems/daily-temperatures
Complexity:
Date : 01 / Feb / 2024

Comment:
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int,int> > sortedTempraturesWithIndex;
        vector<int> daysToWait(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            sortedTempraturesWithIndex.push_back(make_pair(temperatures[i], i));
        }
        sort(sortedTempraturesWithIndex.begin(), sortedTempraturesWithIndex.end());
        for(int i=0;i<temperatures.size();i++){
            cout << temperatures[i] << " "<< findNextWarmer(temperatures[i], sortedTempraturesWithIndex);
        }
        return daysToWait;
    }

    int findNextWarmer(int temprature, vector<pair<int,int>> sortedTempraturesWithIndex){
        cout << endl;
        for(int i=0;i<sortedTempraturesWithIndex.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << i;
        }
        cout << endl;
        for(int i=0;i<sortedTempraturesWithIndex.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << sortedTempraturesWithIndex[i].first;
        }
        cout << endl;
        int l=0, r= sortedTempraturesWithIndex.size()-1;
        while(l<r){
            int mid = (r-l+1)/2;
            cout << l << " "<< r << mid << " " << endl;
            if(sortedTempraturesWithIndex[mid].first <= temprature){
                l = mid;
            }else{
                r = mid;
            }
        }
        return sortedTempraturesWithIndex[l].second;
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
    Solution s;
    int t1[] = {73,74,75,71,69,72,76,73};
    int e1[] = {1,1,4,2,1,1,0,0};
    vector<int> tc1 = makeVectorFromArray(t1, sizeof(t1));
    vector<int> eo1 = makeVectorFromArray(e1, sizeof(e1));
    printVector(tc1);
    s.dailyTemperatures(tc1);
    
    // int tc1ExpectedOutput = 2;
    // int output = s.majorityElement(vec);
    // string passed = tc1ExpectedOutput == output == 1 ? "passed" : "failed";
    // cout << "Output: " << output << " Passed?: " << passed << endl;
    return 0;
}