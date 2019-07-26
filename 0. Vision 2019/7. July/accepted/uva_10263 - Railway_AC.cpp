/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10263
Date : 26 / July / 2019
Comment: not so hard if you have the template.
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
double myX, myY;
double pointToLineDistanceMain(Point p, Line l){
    double lineLength = pointDistance(l.lp, l.rp);
    double u,intersectionX, intersectionY;
    double p1 = p.x, p2 = p.y, x1 = l.lp.x, y1 = l.lp.y, x2 = l.rp.x , y2 = l.rp.y;

    u = ( (p1 - x1 ) * (x2 - x1) +
          (p2 - y1) * (y2-y1) ) /
          (lineLength * lineLength);
    //msg("U", u)
    if(u < 0.0f || u >=1.0f){

        if(pointDistance(l.rp, p) < pointDistance(l.lp, p)){
            intersectionX = l.rp.x;
            intersectionY = l.rp.y;
        }else{
            intersectionX = l.lp.x;
            intersectionY = l.lp.y;
        }
        //msg2("Intersection2", intersectionX, intersectionY)
        myX = intersectionX;
        myY = intersectionY;
        return min( pointDistance(l.rp, p), pointDistance(l.lp,p) );
        //return 0; // closest point does not fall within the line segment
    }
    intersectionX = x1 + u *(x2-x1);
    intersectionY = y1 + u *(y2-y1);
    //msg2("Intersection1", intersectionX, intersectionY)
    myX = intersectionX;
    myY = intersectionY;
    return pointDistance( Point(intersectionX, intersectionY), p );
}
void show(Line mnLine){
    cout << "( " << mnLine.lp.x << "," << mnLine.lp.y << " )->( " << mnLine.rp.x << ", " << mnLine.rp.y << ")"  << endl;
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
void clean(double &a){
    if(fabs(a-0)<EPS){
        a = 0;
    }
}
int main(){
    double x,y,n;
    while(cin >> x >> y){
        Point p(x,y);
        vector<Point>points;
        vector<Line>lines;
        Line mainLine;
        double mnDist, dist;
        cin >> n;
        n++;
        while(n--){
            cin >> x >> y;
            points.push_back( Point(x,y) );
        }
        for(int i=1;i<points.size();i++){
            Line l;
            pointsToLine(points[i], points[i-1],l);
            lines.push_back( l );
        }
        mnDist = INT_MAX*1.0;
        for(int i=0;i<lines.size();i++){
            dist = pointToLineDistanceMain( p, lines[i] );
            if(mnDist > dist){
                mnDist = dist;
                mainLine = lines[i];
            }
        }
        pointToLineDistanceMain( p, mainLine );
        clean(myX);
        clean(myY);
        printf("%.4f\n%.4f\n",myX, myY );
        //cout << myX <<endl << myY << endl;

    }
    return 0;
}
