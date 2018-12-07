/*
Minhazul Hayat Khan
Problem Name: A - Chewbaсca and Number
Problem Link: http://codeforces.com/problemset/problem/514/A
Date : 5/1/18
*/
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int  i;
    string str = "000000000000000000",temp;
    cin >> str;
    temp = str;
    for(i=0;str[i];i++){
        //cout <<  '9' - str[i] << endl;

        if(9 - (str[i]-'0') <=  (str[i] - '0' )){
            str[i] = '9' - str[i] + '0';
        }
    }
    if(str[0] == '0'){
        str[0] = '9';
    }
    for(i=0;str[i];i++){
            cout << (char)str[i];

    }
    cout << endl;


    return 0;
}
