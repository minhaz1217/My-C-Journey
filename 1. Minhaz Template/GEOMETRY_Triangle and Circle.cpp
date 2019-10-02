/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / August / 2019
Comment: GEOMETRY RECTANGLE TRIANGLE AND CIRCLE
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

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

struct Rect{
    double l,r,t,b;
    Rect(){}
    Rect(double _l, double _r, double _t, double _b):l(_l),r(_r),t(_t),b(_b){}
};
bool pointInsideRect(Rect r, Point p ){
    if( p.x >= r.l && p.x<=r.r && p.y <= r.t && p.y >= r.b ){
        return true;
    }else{
        return false;
    }
}
Rect commonRect(Rect a, Rect b){
    vector<double> x,y;
    x.push_back(a.l);
    x.push_back(a.r);
    x.push_back(b.l);
    x.push_back(b.r);
    y.push_back(a.b);
    y.push_back(a.t);
    y.push_back(b.b);
    y.push_back(b.t);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    Rect r(-1,-1,-1,-1);
    for(int i=1;i<x.size();i++){

        if( isInside(x[i-1], x[i], a.l, a.r) && isInside(x[i-1], x[i], b.l, b.r) ){
            if(r.l == -1){
                r.l = x[i-1];
                r.r = x[i];
            }else{
                r.r = x[i];
            }
        }
    }
    for(int i=1;i<y.size();i++){
        if( isInside(y[i-1], y[i], a.b, a.t) && isInside(y[i-1], y[i], b.b, b.t) ){
            if(r.b == -1){
                r.b = y[i-1];
                r.t = y[i];
            }else{
                r.t = y[i];
            }
        }
    }
    return r;
}
Rect commonRectSmall(Rect a, Rect b){
    Rect r;
    r.l = max(a.l,b.l);
    r.r = min(a.r,b.r);
    r.b = max(a.b,b.b);
    r.t = min(a.t,b.t);
    if(r.l > r.r || r.b > r.t){
        r = Rect(-1,-1,-1,-1);
    }
    return r;
}
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
double mcos(double degree){
    /// takes input in degree outputs in degree
    return ( cos( DEG_to_RAD(degree) ) );
}
double cosineRule(double a , double b, double C){
        // c2 = a2 + b2 - 2.a.b.cos(C); is the include angle of a,b
    /// C is in degree
    a= sqrt(a*a + b*b - 2.0*a*b* mcos(C) );
    return a;
}

double msin(double degree){
    /// takes input in degree outputs in degree
    return ( sin( DEG_to_RAD(degree) ) );
}
int main(){
    double x1,x2,x3,y1,y2,y3,g,f,c,r;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        //cout << x1 << ", " << y1 << "  " << x2 << ", " << y2 << "  " << x3 << ", " << y3 << endl;
        printf("%.2f\n", 2*acos(-1)*r);
    }
    return 0;
}
