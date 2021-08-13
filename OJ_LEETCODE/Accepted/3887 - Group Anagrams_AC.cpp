/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 12 / August / 2021
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int> >  sortedStrings;
        map<string, vector<string> > mp;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            if(mp.find(str) == mp.end()){
                vector<string> vec;
                mp[ str ] = vec;
            }
            mp[ str ].push_back(strs[i]);
        }

        vector<vector<string> > result;
        for(map<string, vector<string> >::iterator it = mp.begin();it!=mp.end();it++){
            result.push_back(it->second);
        }
        return result;
    }
};

int main(){

    return 0;
}
