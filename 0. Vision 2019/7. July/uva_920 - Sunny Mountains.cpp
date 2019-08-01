/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 26 / July / 2019
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
void pointsToLine(Point p1, Point p2, Line &l){
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
}

double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
double pointToLineDistance(Point p, Line l){
    double dist = ( fabs(l.a*p.x +l.b*p.y + l.c )/ sqrt( l.a*l.a + l.b*l.b ) );
    if(dist <EPS){
        return min( pointDistance(l.rp, p), pointDistance(l.lp,p) );
    }
    return dist;
}
double pointToLineDistanceMain(Point p, Line l){
    double lineLength = pointDistance(l.lp, l.rp);
    double u;
    double p1 = p.x, p2 = p.y, x1 = l.lp.x, y1 = l.lp.y, x2 = l.rp.x , y2 = l.rp.y;

    u = ( (p1 - x1 ) * (x2 - x1) +
          (p2 - y1) * (y2-y1) ) /
          (lineLength * lineLength);
    msg("U", u)
    if(u < 0.0f || u >=1.0f){
        return min( pointDistance(l.rp, p), pointDistance(l.lp,p) );
        //return 0; // closest point does not fall within the line segment
    }
    double intersectionX = x1 + u *(x2-x1);
    double intersectionY = y1 + u *(y2-y1);
    msg2("Intersection", intersectionX, intersectionY)
    return pointDistance( Point(intersectionX, intersectionY), p );
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
void show(Line mnLine){
    cout << "( "<< mnLine.lp.x <<","<< mnLine.lp.y <<" )->( "<< mnLine.rp.x <<", " << mnLine.rp.y << ")" << endl;
}
void show2(Line mnLine){
    cout << "( "<< mnLine.lp.x <<","<< mnLine.lp.y <<" )->( "<< mnLine.rp.x <<", " << mnLine.rp.y << ")" << endl;
    cout << ""<< mnLine.a <<"x + "<< mnLine.b <<"y + "<< mnLine.c <<" = 0" << endl;
}
int main(){

    Line tl;
    pointsToLine( Point(1700,600), Point(1500,800), tl );
    Point p(1800,700);
    show2(tl);
    //cout << pointToLineDistanceMain(p,tl) << endl;
    Point p1(2400,500), p2(1954.88,500);
    cout << pointDistance(Point(1800,700),Point(1600,700)) << endl;
    cout << pointDistance(Point(1500,800),Point(1207.99,800)) << endl;
    cout << pointDistance(Point(2400,500),Point(1954.88,500)) << endl;
    cout << pointDistance(Point(2800,00),Point(2400,500)) << endl;
    cout << pointDistance(Point(5,5),Point(6,0)) << endl;



//
//    msg("MAIN", pointToLineDistanceMain(Point(10000,0), tl))
//    msg("MAIN 2" , pointToLineDistance(Point(10000,0), tl))
//    long long int tc,n;
//    double x,y,dist,sum;
//    cin >> tc;
//    while(tc--){
//        cin >> n;
//        sum = 0;
//        vector<Point> points;
//        vector<Line>lines;
//        while(n--){
//            cin >> x >> y;
//            points.push_back(Point(x,y));
//        }
//        sort(points.begin(), points.end());
//        reverse(points.begin(),points.end());
//        for(int i=1;i<points.size();i++){
//            Line l;
//            pointsToLine(points[i], points[i-1], l);
//            lines.push_back(l);
//        }
//        Point p = Point(100000,0);
//        for(int i=0;i<lines.size();i++){
//            Line l = lines[i];
//            show(l);
//            show(p);
//            dist =pointToLineDistanceMain(p,l);
//            msg("DISTANCE", dist)
//            x = p.x - dist;
//            y = p.y;
//            show(Point(x,y));
//            sum += pointDistance(Point(x,y), l.lp);
//            msg(i,sum);
//            p = l.lp;
//        }
//    }
    return 0;
}
