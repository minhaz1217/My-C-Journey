/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 04 / 07 / 2020
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    bool misMatchFound = false;
    string mainString, str,outputString = "";
    vector<string> strings;
    getline(cin,mainString);
    stringstream ss(mainString);
    while(ss>>str){
        strings.push_back(str);
    }
    for(int i=0;i<strings[0].size();i++){
        char c = strings[0][i];
        misMatchFound = false;
        for(int j=0;j<strings.size();j++){
            if(strings[j][i] != c){
                misMatchFound = true;
                break;
            }
        }
        if(misMatchFound){
            outputString += "?";
        }else{
            outputString += c;
        }
    }
    cout << outputString << endl;
    return 0;
}
