/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name: --- Day 9: Disk Fragmenter ---
Problem Link: https://adventofcode.com/2024/day/9
Date : 11 / 12 / 2024
Comment: input is very big had to use in.txt file to input and out.txt for output
*/

#include<bits/stdc++.h>
using namespace std;

long long int leftHalf(long long int a);
long long int rightHalf(long long int a);
void simulate();

vector<long long int> vec;
vector<long long int> newVec;

int main(){
    long long int a;
    while(cin >> a){
        vec.push_back(a);
    }

    for(int i=0;i<25;i++){
        simulate();
//        cout << i << ": " << vec.size() << endl;
//        for(auto x: vec){
//            cout << x << " ";
//        }
//        cout << endl;
    }
    cout << "Total Stones after 25 blinks: " << vec.size() << endl;
    return 0;
}

void simulate(){
    newVec.clear();
    for(int i=0;i<vec.size();i++){
        if(vec[i] == 0){
            newVec.push_back(1);
        }else if( ((int)log10(vec[i])+1) % 2 == 0 ){
            newVec.push_back(leftHalf(vec[i]));
            newVec.push_back(rightHalf(vec[i]));
        }else{
            newVec.push_back(vec[i]*2024);
        }
    }
    vec = newVec;
}

long long int leftHalf(long long int a){
    int len = (int)log10(a)+1;
    return (long long int)a/ pow(10, len/2);
}

long long int rightHalf(long long int a){
    int len = (int)log10(a)+1;
    return (long long int)a % (long long int)pow(10, len/2);
}

/* 55312
125 17

*/
