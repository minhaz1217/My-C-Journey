/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3788/
Date : 29 / June / 2021
Comment: normal subset matching with letters.
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
abcde
a bb acd ace
output : 3

dsahjpjauf
ahjpjau ja ahbwzgqnuk tnmlanowax
output : 2
*/

class Solution {
public:
    bool findWord(vector<vector<int> > &letters, string word){
        if(letters[word[0] -'a'].size() <= 0){
            return false;
        }
        int currentValue = letters[ word[0] -'a' ][0];
        //msg(word,currentValue)
        for(int i=1;i<word.size();i++){
            int x = word[i] - 'a';
            if(letters[x].size() <= 0){
                return false;
            }
            int pos = upper_bound( letters[ x ].begin(), letters[x].end(), currentValue ) - letters[x].begin();
            //msg(word[i], pos)
            if(pos >= letters[ x ].size()){
                return false;
            }else{
                currentValue = letters[x][pos];
            }
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int> > letters;
        for(int i=0;i<27;i++){
            vector<int> vec;
            letters.push_back(vec);
        }
        for(int i=0;i<s.size();i++){
            letters[s[i] - 'a'].push_back(i);
        }
        int counter = 0;
        for(int i=0;i<words.size();i++){
            if(findWord(letters, words[i])){
                counter++;
            }
        }
        return counter;
    }
};
int main(){
    string text,str,tempStr;
    vector<string> words;
    cin >> text;
    cin.ignore();
    getline(cin, str);
    stringstream stringStream(str);
    while(stringStream >> tempStr){
        words.push_back(tempStr);
    }
    Solution solution;
    cout << solution.numMatchingSubseq(text, words) << endl;

//    cout << text << endl;
//    for(int i=0;i<words.size();i++) cout << words[i] << " ";
//    cout << endl;
    return 0;
}
