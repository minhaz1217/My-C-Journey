/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-673
Date : 24 / June / 2019
Comment: problem is with getline, the problem statement doesn't say that there will be empty string.
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
    long long int tc,flag;
    string str;
    cin >> tc;
    cin.ignore();
    while(tc--){
        stack<char>st;
        getline(cin,str);
        flag = 1;
        for(int i=0;i<str.size();i++){
            if(str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }else if(str[i] == ')'){
                if(st.size() == 0 || st.top() != '('){
                    flag = 0;
                    break;
               }else{
                   st.pop();
               }
            }else{
                if(st.size() == 0 || st.top() != '['){
                    flag = 0;
                    break;
               }else{
                   st.pop();
               }
            }
        }

        if(flag == 0 || st.size()>0){
            cout << "No" <<endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
