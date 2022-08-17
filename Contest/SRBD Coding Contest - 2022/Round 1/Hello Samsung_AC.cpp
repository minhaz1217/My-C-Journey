/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/hello-samsung
Complexity:
Date : 16 / Aug / 2022

Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char toLower(char a){
    if(a >= 'A' && a <='Z'){
        return a - 'A' + 'a';
    }
    return a;
}
bool findChar(string str, char charToFind, int start, int end){
    for(int i=start;i<=end;i++){
        if( (str[i]) == charToFind){
            return true;
        }
    }
    return false;
}
int main(){
    _INIT;
    string str, str2 = "Samsung";
    cin >> str;
    bool found = true;
    for(int i=0;str2[i];i++){
        if(findChar(str, str2[i], i , str.size()-1) == false){
            found = false;
            break;
        }
    }
    if(found){
        cout << "SRBD" << endl;
    }else{
        cout << "GHOST" << endl;
    }
    return 0;
}
