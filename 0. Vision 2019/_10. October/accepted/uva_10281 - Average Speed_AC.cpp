/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10281
Date : 20 / October / 2019
Comment: easy mathematics
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
    string str;
    char c;
    double sum, prev,ss, mm,hh,speed,prevSpeed,time;
    prev = 0;
    prevSpeed = 0;
    while(getline(cin, str)){
        stringstream sss(str);
        if(str.size()>8){
            sss >> hh >> c >> mm  >> c >> ss >> speed;
            time = hh * 3600 + mm * 60 + ss;
            sum = sum + (time-prev)*prevSpeed;
            prev = time;
            prevSpeed = speed/3600;
        }else{
            sss >> hh >> c >> mm >>c>> ss;
            time = hh * 3600 + mm * 60 + ss;
            sum = sum + (time-prev)*prevSpeed;
            prev = time;
            if(hh <10){
                cout << 0 << hh;
            }else{
                cout << hh;
            }
            cout << ":";
            if(mm <10){
                cout << 0 << mm;
            }else{
                cout << mm;
            }
            cout << ":";
            if(ss <10){
                cout << 0 << ss;
            }else{
                cout << ss;
            }
            printf(" %.2f km\n",sum);
        }
    }
    return 0;
}
