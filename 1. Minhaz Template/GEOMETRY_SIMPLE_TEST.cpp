/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 08 / August / 2019
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

double triangleArea( double a, double b, double c ){
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}

void testTriangleArea(){ // area from a.x, a.y, b.x,b.y, c.x,c.y
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "AREA: " << triangleArea( hypot(x1 - x2, y1 - y2) ,hypot(x1-x3, y1-y3), hypot(x2-x3, y2-y3)) << endl;
}
int main(){
    double a,b,c;
    //testTriangleArea();
    while(1){
    cin >> a >> b >> c;
        msg3(a,b,c, triangleArea(a,b,c))
    }
    return 0;
}
