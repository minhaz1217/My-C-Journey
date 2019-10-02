/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-245
Date : 11 / September / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    string str, st,temp,myWord;
    int pos;
    char c;
    deque<string>vec;
    while(getline(cin, str)){
        if(str == "0"){
            break;
        }
        for(int i=0;i<str.size();i++){
            c = str[i];
            if( (c>='a' && c<='z') || (c>='A' && c<='Z') ){
                temp.push_back(c);

            }else if(c >='0' && c<='9'){
                if(temp.size()>0 && temp!=" "){
                    vec.push_front(temp);
                }
                temp = "";
                msg3("FOUND", c-'0', vec.size(), vec[c-'0'-1])
                pos = c - '0';
                myWord = vec[pos-1];
                vec.erase(vec.begin()+pos);
                vec.push_front(myWord);
                cout << myWord << endl;
            }else{
                if(temp.size()>0 && temp!=" "){
                    vec.push_front(temp);
                }
                temp = "";
            }
        }
    }



    return 0;
}
