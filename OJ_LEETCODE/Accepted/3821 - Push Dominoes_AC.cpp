/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3821/
Date : 21 / July / 2021
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
    string pushDominoes(string dominoes) {
        int l[ 100005 ], r[ 100005 ], lastR = INT_MAX, lastL = INT_MAX;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i] == 'R'){
                lastR = i;
                lastL = INT_MAX;
            }else if(dominoes[i] == 'L'){
                lastL = i;
                lastR = INT_MAX;
            }
            r[i] = lastR == INT_MAX ? lastR : abs(lastR - i);
        }
        lastR = INT_MAX, lastL = INT_MAX;
        for(int i=dominoes.size()-1;i>=0;i--){
            if(dominoes[i] == 'R'){
                lastR = i;
                lastL = INT_MAX;
            }else if(dominoes[i] == 'L'){
                lastL = i;
                lastR = INT_MAX;
            }
            l[i] = lastL == INT_MAX ? lastL : abs(lastL - i);
        }

        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i] == '.'){
                if(l[i] > r[i] && r[i] != INT_MAX){
                    dominoes[i] = 'R';
                }else if(r[i] > l[i] && l[i] != INT_MAX){
                    dominoes[i] = 'L';
                }
            }
        }
        return dominoes;
    }
};
int main(){

    return 0;
}
