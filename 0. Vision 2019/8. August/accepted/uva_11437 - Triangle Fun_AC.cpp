/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11437
Date : 08 / August / 2019
Comment: easy if you have the templates and know how to use it. otherwise very very hard. AC in one go.
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
struct Line{
    double a, b, c;
    Point lp,rp;
    Line(){}
    Line(double _a, double _b,double _c):a(_a), b(_b), c(_c){}
    Line(Point p1, Point p2){
        if (fabs(p1.x - p2.x) < EPS){
            a = 1.0;
            b = 0.0;
            c = -p1.x; // default values
        }else{
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0; // IMPORTANT: we fix the value of b to 1.0
            c = -(double)(a * p1.x) - p1.y;
        }
        if(p1.x > p2.x){
            swap(p1,p2);
        }
        lp = p1;
        rp = p2;
    }
};

Line pointsToLine(Point p1, Point p2){
    Line l;
    if (fabs(p1.x - p2.x) < EPS){
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x; // default values
    }else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    if(p1.x > p2.x){
        swap(p1,p2);
    }
    l.lp = p1;
    l.rp = p2;
    return l;
}

double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
double RAD_to_DEG(double rad){
    return rad*180.0 / acos(-1);
}
double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


Point changeLineLength( Point p1, Point p2, double sz ){
    double n = sz;
    double D = pointDistance(p1,p2);
    Point p;
    p.x = ((p2.x -p1.x)*n) / D + p2.x;
    p.y = ((p2.y -p1.y)*n) / D + p2.y;
//    p.y = ((1.0-n/D)*p1.y + (n/D)*p2.y);
    return p;
}
void show(Line mnLine){
    cout << "( " << mnLine.lp.x << "," << mnLine.lp.y << " )->( " << mnLine.rp.x << ", " << mnLine.rp.y << ")"  << endl;
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
bool areParallel(Line l1, Line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areIntersect(Line l1, Line l2, Point &p) {
    if (areParallel(l1, l2)){
            return false;
    }
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS){
            p.y = -(l1.a * p.x + l1.c);
        }else{
            p.y = -(l2.a * p.x + l2.c);
        }
        return true;
}
double triangleArea( double a, double b, double c ){
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}
int main(){
    double tc,x,y,distAB,distAC,distBC,aa,bb,cc,area;
    cin >> tc;
    while(tc--){
        Point a,b,c,d,e,f,p,q,r;
        cin >> x >> y;
        a = Point(x,y);
        cin >> x >> y;
        b = Point(x,y);
        cin >> x >> y;
        c = Point(x,y);
        distAB = pointDistance(a,b);
        distAC = pointDistance(a,c);
        distBC = pointDistance(b,c);

        f = changeLineLength(b, a, -distAB/3.0);
        e = changeLineLength(a, c, -distAC/3.0);
        d = changeLineLength(c, b, -distBC/3.0);
        Line ab,bc,ac,ad,be,cf;
        areIntersect(pointsToLine(a,d), pointsToLine(c,f), r );
        areIntersect(pointsToLine(a,d), pointsToLine(b,e), p );
        areIntersect(pointsToLine(c,f), pointsToLine(b,e), q );

        aa = pointDistance(r,q);
        bb = pointDistance(r,p);
        cc = pointDistance(p,q);
        area = triangleArea(aa,bb,cc);
        printf("%.0f\n", area);
    }

    return 0;
}
