/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 07 / August / 2019
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



#define EPS 1e-3
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
double DEG_to_RAD(double th){
    return (th * acos(-1.0)/180.0);
}
double RAD_to_DEG(double rad){
    return rad*180.0 / acos(-1.0);
}
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
Point rotateAroundPoint(Point p, Point rotateAround, double degree){ // degree in degree
    cc(degree)
    Point d = rotate(Point(p.x-rotateAround.x, p.y-rotateAround.y), degree);
    d.x += rotateAround.x;
    d.y += rotateAround.y;
    return d;
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
int main(){
    double r,h,d,c,h1,h2,th;
    cin >> r >> d >> h;
    c = 2.0 * r * sqrt( 1.0 - ( ((r-d)/r)*((r-d)/r)) );
    h1 = h2 = RAD_to_DEG( acos( c/(2.0*r) ) );
    th = RAD_to_DEG( acos( (2.0*r*r - c*c)/(2.0*r*r) ) );
    msg2(c,h1,th)
    Point p(100.0, h);
    Point p2 = rotateAroundPoint( Point(100.0+r, h), p, 180.0-h1);
    Point p3 = rotateAroundPoint( p, p2, 360.0-th);
    show(p);
    show(p2);
    show(p3);
    show( rotateAroundPoint( Point(100+r, r), Point(100, r), 180.0+ ((180.0+th)/2) ) );

    return 0;
}
