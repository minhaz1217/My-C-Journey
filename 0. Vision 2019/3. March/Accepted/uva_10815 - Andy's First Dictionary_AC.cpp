/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10815#author=thestyx
Date : 25 / March / 2019
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

set<string>st;
void makeWord(string str){
    string temp ="";
    for(int i=0;i<str.size();i++){
        if(str[i] >='a' && str[i]<='z'){
            temp.push_back(str[i]);
        }else if(str[i] >='A' && str[i]<='Z'){
            temp.push_back( (str[i]-'A'+'a') );
        }else{
            st.insert(temp);
            temp = "";
        }
    }
    st.insert(temp);
}
int main(){
    string str,temp;
    while(getline(cin, str) ){
        //cout << str << endl;
        stringstream ss(str);
        while(ss >> temp){
            makeWord(temp);
        }
    }
    set<string>::iterator it;
    for(it = st.begin();it!=st.end();it++){
        if(it->size() ==0){
            continue;
        }
        cout << *it <<endl;
    }

    return 0;
}
