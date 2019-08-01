/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-191
Date : 26 / July / 2019
Comment: tried to solve using the cp template but failed
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


struct Point{
    double x, y;
    Point()
    {
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	return true;

	return false;
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

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false; // Doesn't fall in any of the above cases
}
struct Line{
    Point a,b;
    Line(){}
    Line(Point _a, Point _b): a(_a), b(_b){}

};
Line makeLine(int a, int b , int c , int d){
    Point p = {a,b}, q = {c,d};
    Line l = {p,q};
    return l;
}

bool doIntersect(Line a, Line b){
    return doIntersect(a.a, a.b, b.a,b.b);
}
int main(){
    double xstart, ystart, xend, yend,xleft, ytop,xright,ybottom,tc;
    bool flag;
    Line ab,bc,cd,da, pp;
    Point a,b,c,d, inter;
    cin >> tc;
    while(tc--){
        cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
        a = Point(xleft, ybottom);
        b = Point(xright,ybottom);
        c = Point(xright, ytop);
        d = Point(xleft, ytop);
        pp = makeLine(xstart, ystart, xend, yend);
        ab = Line(a,b);
        bc = Line(b,c);
        cd = Line(c,d);
        da = Line(d,a);
        if( (xstart >= xleft && xstart <=xright && ystart >= ybottom && ystart<=ytop) || (xend >= xleft && xend <=xright && yend >= ybottom && yend<=ytop)){
            cout << "T" << endl;
        }else if( doIntersect(ab,pp) || doIntersect(bc,pp) || doIntersect(cd,pp) || doIntersect(da,pp) ){
            cout << "T" << endl;
        }else{
            cout << "F" << endl;
        }
    }
    return 0;
}
