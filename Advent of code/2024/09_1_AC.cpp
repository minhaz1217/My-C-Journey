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

string str, str2;

int main(){
    vector<int> vec;
    int id = 0;
    cin >> str;
//    cout<< "RESULT " << str << endl << endl;
//    cout << str.size() << endl;
    for(int i=0;str[i];i++){
        int counter = str[i] - '0';

        for(int j=0;j<counter;j++){
            if(i%2 == 0){
                // file
                vec.push_back(id);
            }else{
                // empty
                vec.push_back(-1);
            }
        }
        if(i%2 != 0){
            id++;
        }
    }
    int lastPtr = vec.size()-1;

    for(int i=0;i<vec.size();i++){
        if(vec[i] == -1){
            while(vec[lastPtr] == -1 && lastPtr > i){
                lastPtr--;
            }
            swap(vec[i], vec[lastPtr]);
        }
    }

    long long int checkSum  = 0;
    for(int i=0;vec[i]!=-1;i++){
        checkSum += (long long int)( vec[i] * i );
    }
    cout << "Size: " << vec.size() << endl;
    cout << "Check Sum: " << checkSum << endl;
    return 0;
}
