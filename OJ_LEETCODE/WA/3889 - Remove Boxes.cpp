/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3889/
Date : 14 / August / 2021
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
/*
[1,3,2,2,2,3,4,3,1]
output: 23
*/



template <typename T>
class LeetCodeInputTaker{
vector< vector<string> > vectorVectorString(string str){
    vector<vector<string> > mainVec;
    str = str.substr( 1, str.size()-2 );
    while(str.size() > 0){
        int leftBracketPosition = str.find('[');
        if(leftBracketPosition == -1){
            break;
        }
        int rightBracketPosition = str.find(']');
        string workingString = str.substr( leftBracketPosition+1, rightBracketPosition - leftBracketPosition-1);
        str = str.substr(rightBracketPosition+1, str.size());
        mainVec.push_back(csvToVector(workingString));
    }
    return mainVec;
}

vector<string> csvToVector(string str){
    string tempStr = str;
    vector<string> insideVector;
    int commaPosition = tempStr.find(',');
    while(tempStr.size() > 0){
        commaPosition = tempStr.find(',');
        if(commaPosition == -1){
            insideVector.push_back(tempStr);
            break;
        }
        string tempStr2 = tempStr.substr(0, commaPosition);
        insideVector.push_back(tempStr2);
        tempStr = tempStr.substr(commaPosition+1, tempStr.size());
    }
    return insideVector;
}

vector<string> vectorString(string str){
    int leftBracket = str.find('[');
    int rightBracket = str.find(']');
    string workingString = str.substr( leftBracket +1 , rightBracket - leftBracket -1 );
    return csvToVector(workingString);
}

vector<T> convertFromString(vector<string> vec){
    int a;
    vector<T> nestedVec;
    for(int j=0;j<vec.size();j++){
        stringstream ss(vec[j]);
        T a;
        ss >> a;
        nestedVec.push_back(a);
    }
    return nestedVec;
}

vector<vector<T> > convertFromString(vector<vector<string> > vec){
    vector<vector<T> > mainVec;
    for(int i=0;i<vec.size();i++){
        mainVec.push_back(convertFromString( vec[i] ));
    }
    return mainVec;
}

public:
    vector<vector<T> > takeVV(){
        string str;
        getline(cin, str);
        return convertFromString(vectorVectorString(str));
    }
    vector<T> takeV(){
        string str;
        getline(cin, str);
        return convertFromString(vectorString(str));
    }
    void display(vector<vector<T> > input, int padding = 5){
        for(int i=0;i<input.size();i++){
            for(int j=0;j<input[i].size();j++){
                cout << right << setw(padding) << input[i][j];
            }
            cout << endl;
        }
    }
    void display(vector<T> input, int padding = 5){
        for(int i=0;i<input.size();i++){
            cout << right << setw(padding) << input[i];
        }
        cout << endl;
    }

};




class Solution {
map<  pair< deque<pair<int,int> > , int > ,int> memo;
public:

    deque<pair<int,int> > normalize(deque<pair<int,int> > vec2, int position){
        deque<pair<int,int> > output;
        if(vec2.size() == 0){
            return output;
        }
        deque<pair<int,int> > vec;
        for(int i=0;i<vec2.size();i++){
            if(i != position){
                vec.push_back(vec2[i]);
            }
        }

        int prev = vec[0].first;
        int counter = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first != prev){
                output.push_back(make_pair( prev, counter ));
                counter = vec[i].second;
                prev = vec[i].first;
            }else{
                counter += vec[i].second;
            }
        }
        output.push_back(make_pair(prev, counter));
        return output;
    }

    int dp(deque<pair<int,int> > vec, int position, int cost){
        if(vec.size() == 1){
            return cost;
        }
        vec = normalize(vec, position);
        if(memo.find(make_pair(vec, position)) != memo.end()){
            if(memo[make_pair(vec, position)] >= cost){
                return memo[make_pair(vec, position)];
            }
//            msg(cost, memo[make_pair(vec, position)])
//            cout << "HIT" << endl;
        }
//        for(auto i: vec){
//            cout << i.first << ":" << i.second << " ";
//        }
//        cout << endl;

        int mx = INT_MIN;
        for(int i=0;i<vec.size();i++){
            mx = max(mx, dp( vec,i, cost + ( vec[i].second * vec[i].second ) ));
        }
        memo[make_pair(vec, position)] = mx;
        return mx;
    }


    int removeBoxes(vector<int>& boxes) {
        deque<pair<int, int> > vec;
        int prev = boxes[0], counter = 0;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i] != prev){
                vec.push_back(make_pair( prev,counter ));
                counter = 1;
                prev = boxes[i];
            }else{
                counter++;
            }
        }
        vec.push_back(make_pair(prev, counter));
        return dp(vec,-1, 0);
    }
};

int main(){

    LeetCodeInputTaker<int> inputTaker;
    vector<int> input = inputTaker.takeV();
    Solution solution;
    cout << "Result: " << solution.removeBoxes(input) << endl;


    return 0;
}
