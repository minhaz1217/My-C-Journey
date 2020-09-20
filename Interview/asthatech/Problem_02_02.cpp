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
map<string, int> years;

bool monthAndDateCheck(int d, int m){
    if(m == 2){
        if( d>= 1 && d <= 28){
            return true;
        }
    }else if( (m== 1 ||m == 3|| m==5|| m == 7 || m == 8 || m == 10 || m == 12)){
        if(d>= 1 && d <= 31){
            return true;
        }
    }else{
        if(d>= 1 && d <= 30){
            return true;
        }
    }
    return false;
}
void checkAndInsertCorrectDates(string str){

    int dd,mm,yy;
    stringstream ss(str);
    ss >> dd >> mm >> yy;
    mm *=-1;
    yy *=-1;
    if( yy >= 2013 && yy <= 2015 ){
        if(monthAndDateCheck(dd, mm)){
            if(years.find(str) == years.end() ){
                years[str] = 1;
            }else{
                years[str]++;
            }
        }
    }
}
int convertToInt(string str){
    int a;
    stringstream ss(str);
    ss >> a;
    return a;
}
int main(){
    int lastFoundPos = -99,convertedInt, currMax = 0;
    string str,intString, outputDate="";
    vector<int> possibleLocation;
    map<string, int>::iterator it ,selected;
    int a;
    getline(cin,str);
    for(int i=0;i<=str.size()-4;i++){
        if(str[i] == '-'){
            if(i-lastFoundPos == 3){
                intString = str[i-2];
                 intString+=str[i-1];
                convertedInt = convertToInt(intString);
                if(convertedInt >= 1 && convertedInt <= 12 && lastFoundPos >= 2){
//                    msg("INSERTED", convertedInt)
                    possibleLocation.push_back( lastFoundPos-2 );
                }
            }
            lastFoundPos = i;
        }
    }
    for(int i=0;i<possibleLocation.size();i++){
        checkAndInsertCorrectDates( str.substr(possibleLocation[i], 10) );
    }
    for(it = years.begin();it!= years.end();it++){
        if(it->second > currMax){
            outputDate = it->first;
            currMax = it->second;
        }
    }
    cout << outputDate << endl;
    return 0;
}
