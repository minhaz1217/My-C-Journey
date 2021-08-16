/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3891/
Date : 15 / August / 2021
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
    int convert(char a){
        if(a >= 'a' && a <='z'){
            return a - 'a';
        }else{
            return a - 'A' + 26;
        }
    }

    string minWindow(string s, string t) {

        vector<pair<int,int> > necessaryLetters;
        vector<int> need(54,0), found(54,0);
        bool fullFound = true;
        int mn = INT_MAX, minLeft, minRight,left = -1, right = -1;
        for(int i=0;i<t.size();i++){
            need[ convert(t[i]) ]++;
        }

        for(int i=0;i<s.size();i++){
            if(need[ convert(s[i]) ] > 0){

                found[ convert(s[i])]++;

                fullFound = true;
                for(int j=0;j<54;j++){
                    if(found[j] < need[j]){
                        fullFound = false;
                        break;
                    }
                }
                if(left == -1){
                    left = i;
                }
                if(fullFound){
                    right = i;
                    // cout <<"FULL FOUND " << i << endl;
                }

                if(fullFound){
                    if(found[ convert(s[left]) ] > need[ convert(s[left]) ]){
                        // we reduce the window here.
                        for(int j=left;j<= right ;j++){
                            if( need[ convert(s[j]) ] > 0 ){
                                found[ convert(s[j]) ]--; // at first we reduce by one and then check if everything is alright.
                                fullFound = true;
                                for(int k=0;k<54;k++){
                                    if(found[k] < need[k]){
                                        fullFound = false;
                                        break;
                                    }
                                }
                                if(!fullFound){
                                    left = j;
                                    found[convert(s[j])]++;
                                    break;
                                }else{
                                    left = j;
                                }
                            }

                        }
                    }
                }


                if(left > -1 && right > -1){
                    if(mn > right - left){
                        minLeft = left;
                        minRight = right;
                        mn = right - left;
                    }
                }
                // cout << left << " " << right << endl;
            }
        }

        // cout << left << " " << right << endl;
        // cout << mn << " " << minLeft << " " << minRight << endl;
        if(mn == INT_MAX){
            return "";
        }else{
            return s.substr(minLeft, minRight-minLeft+1);
        }
    }
};
int main(){

    return 0;
}
