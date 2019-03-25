/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10107#author=jehad
Date : 25 / March / 2019
Comment: easy
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long int>vec;
    long long int n,mid;
    while(cin >> n){
        vec.push_back(n);
        sort(vec.begin(),vec.end());
        mid = vec.size()/2;
        //cout << " MID " << mid << endl;
        if(vec.size()%2 == 1){
            cout << vec[mid] << endl;
        }else{
            //cout << vec[mid] << " " << vec[mid-1] << endl;
            cout << (vec[mid] + vec[mid-1])/2 << endl;
        }
    }
    return 0;
}
