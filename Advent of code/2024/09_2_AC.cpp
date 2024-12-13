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
//    for(auto x: vec){
//        cout << x << " ";
//    }
//    cout << endl;
    for(int i=vec.size()-1;i>=0;i--){
        if(vec[i] != -1){
            int currentId = vec[i];
            int gapNeeded = i;
            while(vec[gapNeeded] == currentId && gapNeeded >= 0){
                gapNeeded--;
            }

            gapNeeded = i - gapNeeded;
//            cout << currentId << " : " << gapNeeded << endl;
            int gapCounter = 0;
            for(int j=0;j<vec.size();j++){
                if(vec[j] != -1){
                    gapCounter = 0;
                }else{
                    gapCounter++;
                }
                if(gapCounter == gapNeeded && j < i){
                    for(int k=0;k<gapCounter;k++){
                        swap(vec[i-k], vec[j-k]);
                    }
                    break;
                }
            }
            i -= gapNeeded-1;
        }
    }
//    for(auto x: vec){
//        cout << x << " ";
//    }
//    cout << endl;

    long long int checkSum  = 0;
    for(int i=0;i<vec.size();i++){
        if(vec[i] != -1){
            checkSum += (long long int)( vec[i] * i );
        }
    }
    cout << "Size: " << vec.size() << endl;
    cout << "Check Sum: " << checkSum << endl;
    return 0;
}
