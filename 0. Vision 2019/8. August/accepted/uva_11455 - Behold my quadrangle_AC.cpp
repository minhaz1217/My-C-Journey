/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11455
Date : 12 / August / 2019
Comment: easy if you know the inequality for quadrectangle.
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
    double tc,a,b,c,d;
    cin >> tc;
    while(tc--){
        vector<double>vec;
        cin >> a >> b >> c >> d;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        vec.push_back(d);
        sort(vec.begin(),vec.end());
        a = vec[0];
        b = vec[1];
        c = vec[2];
        d = vec[3];
        if(a == b && b == c && c == d){
            cout << "square" << endl;
        }else if( vec[0] == vec[1] && vec[2] == vec[3] ){
            cout << "rectangle" << endl;
        }else if( a+b+c > d ){
            cout <<"quadrangle" << endl;
        }else{
            cout << "banana" << endl;
        }
    }
    return 0;
}
