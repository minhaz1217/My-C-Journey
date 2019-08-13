/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10297
Date : 13 / August / 2019
Comment: easy problem just solve 3 equations of 3d geometry.
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

#define PI acos(-1)
int main(){
    double a,b,area,d;
    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        d =a ;
        area =  pow((( (6.0/PI) * ( ((PI * a*a*a) / 4.0) - b )) - (d*d*d/2.0) ),1.0/3.0);
        printf("%.3f\n", area);
    }
    return 0;
}
