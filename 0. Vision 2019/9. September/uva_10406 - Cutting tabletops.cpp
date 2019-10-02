/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 02 / September / 2019
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
    if( !(p1 < p2)){
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
void mshow(Line a){
    cout << a.a << "," << a.b << "," << a.c << endl;
}
double polygonArea(const vector<Point> &P){
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++){
        x1 = P[i].x;
        x2 = P[i+1].x;
        y1 = P[i].y;
        y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}
bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
Point polygonCentroid(vector<Point>p){
    /// careful about the rotation, if counter clockwise polygon then gives right answer, if clockwise, then just multiply pp by -1.
    // or center of mass
    if(cw(p[0],p[1],p[2])){
        reverse(p.begin(),p.end());
    }
    double area = polygonArea(p);
    Point pp(0,0);
    for(int i=0;i<p.size()-1;i++){
        pp.x += (p[i].x+p[i+1].x)*(p[i].x * p[i+1].y - p[i+1].x * p[i].y);
        pp.y += (p[i].y+p[i+1].y)*(p[i].x * p[i+1].y - p[i+1].x * p[i].y);
    }
    pp.x = pp.x * 1.0/(6.0*area);
    pp.y = pp.y * 1.0/(6.0*area);
    return pp;
}
double pointToLineDistance(Point p, Line l){
    return ( fabs(l.a*p.x +l.b*p.y + l.c )/ sqrt( l.a*l.a + l.b*l.b ) );
}

void show(Line mnLine){
    cout << "( " << mnLine.lp.x << "," << mnLine.lp.y << " )->( " << mnLine.rp.x << ", " << mnLine.rp.y << ")"  << endl;
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}

Line generatePointsOfALine(Line l){
    double tl= -9999.25, tr = 9999.15;
    l.lp = Point(tl, -(l.a*tl + l.c)/l.b);
    l.rp = Point(tr, -(l.a*tr + l.c)/l.b);
    if(fabs(l.a) < EPS){
        l.lp.x = tl;
        l.rp.x = tr;
        l.lp.y = -l.c/l.b;
        l.rp.y = -l.c/l.b;
    }
    if(fabs(l.b) < EPS){
        l.lp.x = -l.c/l.a;
        l.rp.x = -l.c/l.a;
        l.lp.y = tl;
        l.rp.y = tr;
    }
    if(fabs(l.a)<EPS && fabs(l.b)<EPS){
        l.lp = Point(0,0);
        l.rp = Point(0,0);
    }
    return l;
}
void clean(Point &p){
    if(fabs(p.x-0)<EPS){
        p.x = 0;
    }
    if(fabs(p.y-0)<EPS){
        p.y = 0;
    }
}
void clean(Line &l){
    l.a = fabs(l.a)<EPS?0:l.a;
    l.b = fabs(l.b)<EPS?0:l.b;
    l.c = fabs(l.c)<EPS?0:l.c;
    clean(l.lp);
    clean(l.rp);
}


Point intersectingLineSegment(Point p, Point q, Point A, Point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return Point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}
Point lineToLineIntersection(Line p, Line q){
    p =generatePointsOfALine(p);
    q =generatePointsOfALine(q);
    Point pp = intersectingLineSegment(p.lp, p.rp, q.lp,q.rp);
    return pp;
}

bool cmp(Point a,Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convexHullCo(vector<Point>& a) {
    /// generates a CLOCKWISE polygon.
    // gives right answer for collinear points.
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
int main(){
    show(generatePointsOfALine(pointsToLine(Point(0,0), Point(5,5))));
    show(lineToLineIntersection(pointsToLine(Point(1,1), Point(20,20)), pointsToLine(Point(0,20), Point(20,0)) ));
    double s,n,x,y;

    cin >> s >> n;

    vector<Point>myPoly,poly;
    vector<Line>lines,myLines;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        poly.push_back(Point(x,y));
    }
    convexHullCo(poly);
    poly.push_back(poly[0]);
    for(int i=1;i<poly.size();i++){
        lines.push_back(pointsToLine( poly[i-1], poly[i] ));
    }
    Point p = polygonCentroid(poly);
    msg("MY S", s)
    Line l1,l2;
    for(int i=0;i<lines.size();i++){

        l1 = lines[i];
        l1.c += s;
        l2 = lines[i];
        l2.c -= s;
        double d1 = pointToLineDistance(p, l1);
        double d2 = pointToLineDistance(p, l2);
        //msg(d1,d2)
        if(d1<= d2 ){
            //cc(1)
            myLines.push_back(l1);

        }else{
            //cc(2)
            myLines.push_back(l2);
        }
//        mshow(lines[i]);
//        mshow(myLines[myLines.size()-1]);
//            show(generatePointsOfALine(lines[i]));
//            show(generatePointsOfALine(myLines[myLines.size()-1]));
    }
    myLines.push_back(myLines[0]);
    for(auto i: myLines){
        show(generatePointsOfALine(i));
    }


    for(int i=1;i<myLines.size();i++){
        myPoly.push_back(lineToLineIntersection(myLines[i-1], myLines[i]));
    }

    convexHullCo(myPoly);
    myPoly.push_back(myPoly[0]);
    for(auto i: myPoly){
        msg(i.x,i.y)
    }
    msg(myPoly.size(), polygonArea(myPoly));

    return 0;
}
