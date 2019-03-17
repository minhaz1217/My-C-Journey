/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11988
Date : 18 / March / 2019
Comment: Funny but medium hard string manipulation with vector.
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
    _INIT;
    string str, temp,temp2;
    int start,last;
    while(getline(cin, str)){
        temp = "";
        temp2 = "";
        start = 0;
        last = 1;
        vector<string> st, en;
        for(int i=0;i<str.size();i++){
            if(str[i] == '['){
                if(last == 1){
                    en.push_back(temp);
                }else{
                    st.push_back(temp);
                }
                last = 0;
                temp = "";
                continue;
            }else if(str[i] == ']'){
                if(last == 1){
                    en.push_back(temp);
                }else{
                    st.push_back(temp);
                }
                last = 1;
                temp = "";
                continue;
            }
            temp.push_back(str[i]);
        }
        if(last == 1){
            en.push_back(temp);
        }else{
            st.push_back(temp);
        }
        for(int i=st.size()-1;i>=0;i--){
            cout << st[i];
        }
        for(int i=0;i<en.size();i++){
            cout << en[i];
        }
        cout << endl;
    }
    return 0;
}
