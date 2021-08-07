/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3872/
Date : 07 / August / 2021
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
    map<pair<int,int>, int > pointsArePalindromic; // -3 means unassigned, -2 means not palindrome, -1 means palindrome
    map<pair<int,int>, int> memo;
    string mainString;
    vector<vector<int> > arr;
    vector<pair< int, pair<int,int> > > sortedPoints;
    int arePointsPalindromic(int startPoint, int endPoint){
        int mn = min(startPoint,endPoint);
        endPoint = max(startPoint, endPoint);
        startPoint = mn;
        for(int index1=startPoint,index2=endPoint;index1<index2;index1++,index2--){
            if(mainString[index1] != mainString[index2] ){
                return 0;
            }
        }
        return 1;
    }
    int getNumbers(int startPoint, int endPoint){
        if(startPoint > endPoint){
            return 0;
        }
        if(endPoint == startPoint){
            return 1;
        }
        if(memo.find(make_pair(startPoint, endPoint)) != memo.end()){
            return memo[make_pair(startPoint,endPoint)];
        }
        int mn = 5000;
        for(int i=0;i<arr[ mainString[startPoint]-'a' ].size();i++){
            if( arr[ mainString[startPoint]-'a' ][i] > startPoint ){
                int minPoint = min(startPoint, arr[ mainString[startPoint]-'a' ][i]);
                int maxPoint= max(startPoint, arr[ mainString[startPoint]-'a' ][i]);
                if(pointsArePalindromic[ make_pair(minPoint, maxPoint) ] == -1){
                    pointsArePalindromic[ make_pair(minPoint, maxPoint) ] = arePointsPalindromic(minPoint,maxPoint);
                }
                if(pointsArePalindromic[ make_pair(minPoint, maxPoint) ] == 1){
                    mn = min( mn, 1+getNumbers(maxPoint+1, endPoint) );
                }
            }

        }

        mn = min(mn, 1 + getNumbers(startPoint +1 , endPoint));
//        cout << startPoint << " " << endPoint << ": " << mn << endl;
        memo[ make_pair(startPoint, endPoint) ] = mn;
        return mn;
    }
    int minCut(string s) {
        mainString = s;
        int sz;
        for(int i=0;i<28;i++){
            vector<int> vec;
            arr.push_back(vec);
        }
        for(int i=0;i<s.size();i++){
            arr[ s[i] - 'a' ].push_back(i);
        }
        for(int i=0;i<arr.size();i++){
            sort(arr[i].begin(), arr[i].end(), greater<int>() );
        }

        for(int i=0;i<arr.size();i++){
            sz = arr[i].size()-1;
            for(int j=0;j<sz;j++){
                for(int k=j+1;k<arr[i].size();k++){
                    int startPoint = min(arr[i][j], arr[i][k]);
                    int endPoint = max(arr[i][j], arr[i][k]);
                    if(pointsArePalindromic.find( make_pair(startPoint, endPoint) ) == pointsArePalindromic.end()){
                        pointsArePalindromic[ make_pair(startPoint, endPoint) ] = -1;
                        sortedPoints.push_back( make_pair( endPoint-startPoint , make_pair(startPoint,endPoint) ) );
                    }
                }
            }
        }
        if(pointsArePalindromic.size() == 0){
            return s.size()-1;
        }
        return getNumbers(0, mainString.size()-1)-1;
    }
};
int main(){
    string str;
    cin >> str;
    Solution solution;
    cout << "RESULT: " << solution.minCut(str) << endl;
    return 0;
}
