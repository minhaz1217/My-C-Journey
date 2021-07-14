/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/
Date : 14 / July / 2021
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
    string customSortString(string order, string str) {
        vector<pair<int, char> > vec;
        int cost;
        map<char, int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i +1;
        }
        for(int i=0;i<str.size();i++){
            if(mp.find(str[i]) == mp.end()){
                cost = INT_MAX;
            }else{
                cost = mp[str[i]];
            }
            vec.push_back(make_pair( cost, str[i] ));
        }
        sort(vec.begin(), vec.end());
        string output = "";
        for(int i=0;i<vec.size();i++){
            output += vec[i].second;
        }
        return output;
    }
};
int main(){

    return 0;
}
