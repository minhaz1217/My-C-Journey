/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 28 / October / 2019
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
    bool operator == (Point other) const{
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const{
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
double dist(Point p1, Point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


bool cmp(Point a,Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}


void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
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
    reverse(a.begin(),a.end());
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

double pointToLineDistance(Point p, Line l){
    return ( fabs(l.a*p.x +l.b*p.y + l.c )/ sqrt( l.a*l.a + l.b*l.b ) );
}
double outCircle(Point a, Point b, Point c){
    double aa = dist(a,b), bb = dist(b,c), ccc = dist(c,a);
    vector<Point>vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(a);
    double area = polygonArea(vec);
    double ans = (aa*bb * ccc) / (4.0*area);
    cout << ans << endl;
    return ans;
}
int main(){
    long long int tc,n,p,caseCounter = 1;
    double x,y,area,mx,mmx;
    cin >> tc;
    while(tc--){
        cin >> n;
        mmx = 0;
        for(int i=0;i<n;i++){
            cin >> p;
            vector<Point>points;
            for(int j=0;j<p;j++){
                cin >> x >> y;
//                msg(x,y)
                points.push_back(Point(x,y));
            }


            convexHullCo(points);
            points.push_back(points[0]);
            mx = 0;
            double mn = 999;
            double mdist;
            for(int i=0;i<points.size();i++){
                for(int j=1;j<points.size();j++){
                    if( !(points[j] == points[i] || points[j-1]==points[i]) ){
                        mdist = pointToLineDistance(points[i], pointsToLine(points[j], points[j-1]));
                        mx = max(mx, mdist);
                        mn = min(mn,mdist);
                    }
                }
            }
            mmx = max(mmx,mx);
        }
//        cout << "ENDED" << endl;
//        for(auto it: points){
//            cout << it.x << " " << it.y << endl;
//        }
//        area = polygonArea(points);
//        points.push_back(points[1]);
//        mx = 000;
//        for(int i=2;i<points.size();i++){
//            mx = max(mx, outCircle(points[i-2], points[i-1], points[i]));
//        }
//        cout << mx << endl;


        printf("Case %lld: %.2f\n",caseCounter++, mmx);

    }
    return 0;
}
