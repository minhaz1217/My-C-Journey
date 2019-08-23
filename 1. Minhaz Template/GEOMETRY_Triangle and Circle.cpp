/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-438
Date : 06 / August / 2019
Comment: discovered new equation solving this.
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


struct Point{
    double x, y;
    Point(){
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const {
        if (fabs(x - other.x) > EPS)
                return x < other.x;
        return y < other.y;
    }
};


void makeCircleUsing3Points(Point a, Point b, Point c){
        double f, g, x1 = a.x , y1 = a.y, x2 = b.x, y2 = b.y, x3 = c.x , y3 = c.y,radius;
        f = ( (x1*x1 - x3*x3)*(x1-x2) + (y1*y1 - y3*y3)*(x1-x2) + (x2*x2 - x1*x1)*(x1-x3) + (y2*y2 - y1*y1)*(x1-x3) )/
            ( (y3-y1)*(x1-x2) - (y2-y1)*(x1-x3) );
        f = f/2.0;
        g = ( (x1*x1 - x3*x3)*(y1-y2)
                         + (y1*y1 - y3*y3)*(y1-y2)
                         + (x2*x2 - x1*x1)*(y1-y3)
                         + (y2*y2 - y1*y1)*(y1-y3) ) /( (x3-x1)*(y1-y2) - (x2-x1)*(y1-y3) );
        g = g/2.0;
        c = (x1*x1)*-1 - (y1*y1) - 2.0*g*x1 - 2.0*f*y1;
        radius = sqrt(g*g + f*f - c);
        double centerX = -g, centerY = -f;
}
double triangleArea( double a, double b, double c ){
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}

double triangleAreaFromPoint(Point aa, Point bb, Point cc){
    a = hypot( aa.x-bb.x, aa.y-bb.y );
    b = hypot( bb.x-cc.x, bb.y-cc.y );
    c = hypot( cc.x-aa.x, cc.y-aa.y );
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}
bool isPointInsideCircle(Point center, double radius, Point p){
    if(pointDistance(center, p) <= radius){
        return true;
    }
    return false;
}

int main(){
    double x1,x2,x3,y1,y2,y3,g,f,c,r;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        //cout << x1 << ", " << y1 << "  " << x2 << ", " << y2 << "  " << x3 << ", " << y3 << endl;


        printf("%.2f\n", 2*acos(-1)*r);
    }
    return 0;
}
