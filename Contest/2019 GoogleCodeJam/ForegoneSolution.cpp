/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / April / 2019
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
    long long int tc,n,caseCounter = 1;
    string temp,str,temp2;
    cin >> tc;
    while(tc--){
        cin >> str;
        temp = "";
        temp2 = "";
        for(int i=0;i<str.size();i++){
            if(str[i]!= '4'){
                temp += str[i];
                if(temp2 !=""){
                    temp2 += '0';
                }
            }else{
                temp += '3';
                temp2 += '1';
            }
        }
        cout <<"Case #" << caseCounter++ << ": " << temp << " " << temp2 << endl;
    }
    return 0;
}
