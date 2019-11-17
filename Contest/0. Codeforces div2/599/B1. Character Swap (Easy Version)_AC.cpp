/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / November / 2019
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
    long long int tc,n,counter,mainFlag, flag;
    char a,b;
    string str1,str2;
    cin >> tc;
    while(tc--){
        cin >> n;
        cin >> str1 >> str2;
        counter = 0;
        mainFlag = 0;
        flag = 0;
        for(int i=0;i<n;i++){
            if(str2[i] != str1[i] && flag == 0 && mainFlag == 0){
                a = str1[i];
                b = str2[i];
                flag = 1;
            }else if(str1[i] != str2[i] && flag == 1 && mainFlag == 0){
                if(str1[i] == a && str2[i] == b){
                    mainFlag = 1;
                }
            }
            if(str1[i] != str2[i]){
                counter++;
            }
        }
        if(counter==2 && mainFlag == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }
    return 0;
}
