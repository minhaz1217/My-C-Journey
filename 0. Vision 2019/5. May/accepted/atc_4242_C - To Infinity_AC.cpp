/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://abc106.contest.atcoder.jp/tasks/abc106_c?lang=en
Date : 17 / May / 2019
Comment: Trick problem
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
    long long int currSum = 0, k,c;
    cin >> str >> k;
    for(int i=0;i<str.size();i++){
        c= str[i]-'0';
        if(c == 1){
            k -= 1;
        }else{
            //k -= (c * 5* 1000000000000000);
            cout << c << endl;
            break;
        }
        if(k <= 0){
            cout << c << endl;
            break;
        }
    }
    return 0;
}
