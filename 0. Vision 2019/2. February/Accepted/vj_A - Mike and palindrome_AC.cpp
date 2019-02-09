/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/CodeForces-798A
Date : 09 / February / 2019
Comment: Individual contest 9
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int counter,i,j;
    string str;
    cin >> str;
    i = 0;
    j = str.size()-1;
    counter = 0;
    while(i<j){
       //cout << str[i] << " " << str[j] << endl;
        if(str[i] != str[j]){
            counter++;
        }
        i++;
        j--;
    }
    if(counter == 1){
        cout << "YES" << endl;
    }else{
        if(counter == 0 && str.size()%2 == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
