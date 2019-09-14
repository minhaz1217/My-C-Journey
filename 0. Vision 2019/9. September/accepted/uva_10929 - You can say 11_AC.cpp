/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://uva.onlinejudge.org/external/109/10929.pdf
Date : 15 / September / 2019
Comment: basic number problem.
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
    int a;
    string str,temp;
    while(cin >> str){
        if(str == "0"){
            break;
        }
        a = 0;
        for(int i=0;i<str.size();i++){
            a = a * 10 + str[i]-'0';
            a = a%11;
        }

        if( a== 0){
            cout << str << " is a multiple of 11." << endl;
        }else{
            cout << str << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}
