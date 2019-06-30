/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 30 / June / 2019
Comment: easy string problem that seems like integer problem.
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

string conv(int h, int m){
    string st = "", temp;
    char c;
    if(h<10){
        st += "0";
        c = ('0'+h);
        st += c;
    }else{
        stringstream ss;
        ss << h;
        ss >> temp;
        st += temp;
    }
    if(m < 10){
        st += "0";
        c = ('0'+m);
        st += c;
    }else{
        stringstream ss;
        ss << m;
        ss >> temp;
        st += temp;
    }
    return st;
}
bool checkPalin(string str){
    string temp = str;
    reverse(temp.begin(), temp.end());
    if(str == temp){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int h,m,counter;
    char c;
    string str;
    cin >> h >> c >> m;
    counter = 0;
    while(1){
        if(checkPalin(conv(h,m))){
            cout << counter << endl;
            break;
        }
        m++;
        counter++;
        if(m == 60){
            m = 0;
            h++;
            if(h == 24){
                h = 0;
            }
        }

    }
    return 0;
}
