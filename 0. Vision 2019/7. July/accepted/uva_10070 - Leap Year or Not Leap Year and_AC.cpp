/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10070
Date : 21 / July / 2019
Comment: easy problem. Was getting WA because of a newline, string problem didn't notice it.
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

long long int div(string str, long long int d){
    long long int sz = str.size(), rem = 0;
    for(int i=0;i<sz;i++){
        rem = (rem*10 + (str[i] -'0') )%d;
    }
    return rem;
}
int main(){
    string str;
    unsigned long long int n,hall,counter= 1, buku, leapYear;
    while(cin >> str){
        if(counter>1){
            cout << endl;
        }
        counter++;
        if(div(str, 400)== 0){
            leapYear = 1;
        }else if(div(str, 100) == 0){
            leapYear = 0;
        }else if(div(str, 4) == 0){
            leapYear = 1;
        }else{
            leapYear = 0;
        }
        if(div(str, 15) == 0){
            hall = 1;
        }else{
            hall = 0;
        }
        if(div(str, 55) == 0 && leapYear == 1){
            buku = 1;
        }else{
            buku = 0;
        }

        if(leapYear == 0 && buku == 0 && hall == 0){
            cout << "This is an ordinary year." << endl;
        }else{
            if(leapYear){
                cout << "This is leap year." << endl;
            }
            if(hall){
                cout << "This is huluculu festival year." << endl;
            }
            if(buku){
                cout << "This is bulukulu festival year." << endl;
            }
        }

    }
    return 0;
}
