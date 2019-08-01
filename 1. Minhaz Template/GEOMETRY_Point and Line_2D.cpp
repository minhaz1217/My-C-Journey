/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-378
Date : 26 / July / 2019
Comment: tried to solve using the cp template.
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
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}


double pointToLineDistance(Point p, Line l){
    return ( fabs(l.a*p.x +l.b*p.y + l.c )/ sqrt( l.a*l.a + l.b*l.b ) );
}

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
        return min( pointDistance(l.rp, p), pointDistance(l.lp,p) );
        //return 0; // closest point does not fall within the line segment
    }
    intersectionX = x1 + u *(x2-x1);
    intersectionY = y1 + u *(y2-y1);
    //msg2("Intersection1", intersectionX, intersectionY)
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
void clean(Point &p){
    if(fabs(p.x-0)<EPS){
        p.x = 0;
    }
    if(fabs(p.y-0)<EPS){
        p.y = 0;
    }
}
bool areParallel(Line l1, Line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(Line l1, Line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
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
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}



double angleBetweenPoints(Point a, Point b , Point c){
    /*   a
       /
      /
     b ----- c
    */
    double ab = pointDistance(a,b), bc = pointDistance(b,c), ac = pointDistance(a,c);
    return acos( (bc*bc  + ab*ab - ac*ac)/(2.0*bc*ab) ); // will return the value in radian.

}
Point rotateAroundPoint(Point p, Point rotateAround, double degree){ // degree in degree
    Point d = rotate(Point(p.x-rotateAround.x, p.y-rotateAround.y), degree);
    d.x += rotateAround.x;
    d.y += rotateAround.y;
    return d;
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
void lineFromConstants(double a, double b , double c, Line &l){
    pointsToLine(Point(0, -c/b), Point(-c/a, 0), l);
}

int main(){
    Line l1,l2;
    long long tc;
    Point p;
    cin >> tc;
    double a,b,c,d,flag;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(tc--){
        cin >> a >> b >> c >> d;
        pointsToLine(Point(a,b), Point(c,d), l1);
        cin >> a >> b >> c >> d;
        pointsToLine(Point(a,b), Point(c,d), l2);
        flag = areIntersect(l1,l2,p);
        //msg3("Line1", l1.a,l1.b,l1.c)
        //msg3("Line2", l2.a,l2.b,l2.c)
        if(areSame(l1,l2)){
            cout << "LINE" << endl;
        }else if(flag == 0){
            cout << "NONE" << endl;
        }else{
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
