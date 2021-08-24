/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3904/
Date : 21 / August / 2021
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
    vector<vector<char> > mat;
    bool testSq(int x, int y){
        //cout << x << " " << y << endl;
        map<char, bool> mp;
        for(int i =x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(mat[i][j] == '.'){
                    continue;
                }
                if(mp.find(mat[i][j]) != mp.end()){
                    return false;
                }else{
                    mp[mat[i][j]] = true;
                }
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char> >& board) {
        map<pair<int, char>, bool > row,col,sq;
        mat = board;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                if(row.find(make_pair(i, c)) != row.end()) {
                    //cout << i << " " << c << endl;
                    return false;
                }else{
                    row[ make_pair(i,c) ] = true;
                }
                if(col.find(make_pair(j, c)) != col.end()) {
                    //cout << j << " " << c << endl;
                    return false;
                }else{
                    col[ make_pair(j,c) ] = true;
                }
            }
        }

        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[i].size();j+=3){
                if(!testSq(i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

    return 0;
}
