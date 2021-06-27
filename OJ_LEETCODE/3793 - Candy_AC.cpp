/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3793/
Date : 27 / June / 2020
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    int leftToRightIncrements[20004], rightToLeftIncrements[20004];
    int candy(vector<int>& ratings) {
        leftToRightIncrements[0] = 0;
        int previousNumber = ratings[0];
        int currentCounter = 0,sum = 0;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > previousNumber){
                currentCounter++;
                leftToRightIncrements[i] = currentCounter;
            }else{
                currentCounter = 0;
            }
            previousNumber = ratings[i];
        }

        rightToLeftIncrements[ratings.size()-1] = 0;
        previousNumber = ratings[ratings.size()-1];
        currentCounter = 0;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i] > previousNumber){
                currentCounter++;
                rightToLeftIncrements[i] = currentCounter;
            }else{
                currentCounter = 0;
            }
            previousNumber = ratings[i];
        }

        for(int i=0;i<ratings.size();i++){
            sum += max(leftToRightIncrements[i], rightToLeftIncrements[i])+1;
        }
        return sum;
    }
};
int main(){

    string input;
    char extra;
    int num;
    vector<int>ratings;
    // taking inputs and parsing it.
    cin >> input;
    input = input.substr(1, input.size() -1 );
    cout << input << endl;
    stringstream stringStream(input);
    while(stringStream >> num >> extra){
        ratings.push_back(num);
    }

    // sending the taken input to solve.
    Solution solution;
    cout << solution.candy(ratings) << endl;

    return 0;
}
