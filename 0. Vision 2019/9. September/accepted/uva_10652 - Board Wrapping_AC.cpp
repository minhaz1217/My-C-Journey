/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10652
Date : 03 / September / 2019
Comment: the rotation is the hard part.
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
    bool operator == (Point other) const{
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const{
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
};
double dist(Point p1, Point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
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
vector<Point> polygonRotate(vector<Point> p, double deg){
    Point c = polygonCentroid(p);
    vector<Point> pp;
    for(auto i : p){
        pp.push_back(rotateAroundPoint(i, c, deg));
    }
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
    int tc,n;
    double x,y,h,t,w,area,area2;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<Point>mainPoly;
        area = 0;
        for(int i=0;i<n;i++){
            cin >> x >> y >> w >> h >> t;
            area += w*h;
            w = w/2.0;
            h = h/2.0;
            vector<Point>poly;
            poly.push_back(Point( x + w, y-h ));
            poly.push_back(Point( x + w, y+h ));
            poly.push_back(Point( x - w, y+h ));
            poly.push_back(Point( x - w, y-h ));
            poly.push_back(poly[0]);
            poly = polygonRotate(poly,180.0-t);
            for(auto k: poly){
                mainPoly.push_back(k);
            }

        }
        mainPoly.push_back(mainPoly[0]);
        convexHullCo(mainPoly);
        mainPoly.push_back(mainPoly[0]);
        area2 = polygonArea(mainPoly);
        printf("%.1f %\n", 100.0*area/area2);
    }
    return 0;
}
