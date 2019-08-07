/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10577
Date : 07 / August / 2019
Comment: had to look at hint from the cpbook 3.
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

#define EPS 1e-9
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
double rad, cenX, cenY;
void makeCircleUsing3Points(Point a, Point b, Point c){
        double f, g, x1 = a.x , y1 = a.y, x2 = b.x, y2 = b.y, x3 = c.x , y3 = c.y,radius,cc;
        f = ( (x1*x1 - x3*x3)*(x1-x2) + (y1*y1 - y3*y3)*(x1-x2) + (x2*x2 - x1*x1)*(x1-x3) + (y2*y2 - y1*y1)*(x1-x3) )/
            ( (y3-y1)*(x1-x2) - (y2-y1)*(x1-x3) );
        f = f/2.0;
        g = ( (x1*x1 - x3*x3)*(y1-y2)
                         + (y1*y1 - y3*y3)*(y1-y2)
                         + (x2*x2 - x1*x1)*(y1-y3)
                         + (y2*y2 - y1*y1)*(y1-y3) ) /( (x3-x1)*(y1-y2) - (x2-x1)*(y1-y3) );
        g = g/2.0;
        cc = (x1*x1)*-1 - (y1*y1) - 2.0*g*x1 - 2.0*f*y1;
        radius = sqrt(g*g + f*f - cc);
        double centerX = -g, centerY = -f;
        rad = radius;
        cenX = centerX;
        cenY = centerY;
}
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}

Point rotateAroundPoint(Point p, Point rotateAround, double degree){ // degree in degree
    Point d = rotate(Point(p.x-rotateAround.x, p.y-rotateAround.y), degree);
    d.x += rotateAround.x;
    d.y += rotateAround.y;
    return d;
}
void clean(Point &p){
    if(fabs(p.x-0)<EPS){
        p.x = 0;
    }
    if(fabs(p.y-0)<EPS){
        p.y = 0;
    }
}
void show(Point p){
    clean(p);
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
int main(){
    int caseCounter = 1;
    double n,mxX, mxY,mnX,mnY;
    while(1){
        cin >> n;
        if(n ==0){
            break;
        }
        Point p1,p2,p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        makeCircleUsing3Points(p1,p2,p3);
        Point center(cenX, cenY);
        Point prev = p1;
        mxX = mxY = INT_MIN;
        mnX = mnY = INT_MAX;
        for(int i=0;i<n;i++){
            prev = rotateAroundPoint(prev, center, 360.0/n);
            clean(prev);
            mxX = max(mxX, prev.x);
            mnX = min(mnX, prev.x);
            mxY = max(mxY, prev.y);
            mnY = min(mnY, prev.y);
        }
        printf("Polygon %d: %.3f\n",caseCounter++, ( (mxX - mnX) * ( mxY - mnY )));
    }
    return 0;
}
