/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/external/6/673.pdf
Date : 27 / October / 2019
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
    long long int tc,flag;
    char c;
    string str;
    cin >> tc;
    while(tc--){
        stack<char>st;
        cin >> str;
        flag = 1;
        for(int i=0;i<str.size();i++){
            if(str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }else{
                if(st.empty()){
                    flag = 0;
                    break;
                }
                c = st.top();
                if( (str[i] == ')' && c == '('  )|| ( str[i] ==']' && c =='[' )){
                    st.pop();
                }else{
                    flag = 0;
                    break;
                }
            }
        }
        if(st.size() > 0 || flag == 0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }

    }

    return 0;
}
