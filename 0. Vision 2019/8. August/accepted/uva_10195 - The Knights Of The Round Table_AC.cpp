/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10195
Date : 06 / August / 2019
Comment: just an equation. check for valid line length
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


double area(double ab, double bc, double ca){
    double s = (ab+bc+ca)/2.0;
    return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

int main(){
    double a,b,c,ar,radius;
    while(cin >> a >> b >> c){
        ar = area(a,b,c);
        radius =ar / ( (a+b+c)*.5);
        if(a==0 || b == 0 || c == 0){
            radius = 0;
        }
        printf("The radius of the round table is: %.3f\n", radius);
    }
    return 0;
}
