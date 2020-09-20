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
    int n,iteration=3, lastOpened=1;
    vector<int>vec;
    cin >> n;

    for(int i=2;i<=n;i+=2){
        vec.push_back(i);
    }
    while(!vec.empty()){
        vector<int> vec2;
        for(int i=0;i<vec.size();i++){
            if(i %iteration != 0){
                vec2.push_back(vec[i]);
            }else{
                lastOpened = vec[i];
            }
        }
        vec = vec2;
        iteration++;
    }
    cout << lastOpened << endl;
    return 0;
}
