/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11265
Date : 04 / September / 2019
Comment: simple solution.
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


struct vec{
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(Point a, Point b){
	// convert 2 Points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}
// note: to accept collinear Points, we have to change the ‘> 0’
// returns true if Point r is on the left side of line pq
bool ccw(Point p, Point q, Point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
Point polygonLineIntersectSeg(Point p, Point q, Point A, Point B){
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return Point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

// cuts polygon Q along the line formed by Point a -> Point b
// (note: the last Point must be the same as the first Point)

vector<Point> cutPolygon(Point a, Point b, const vector<Point> &Q){
    vector<Point> P;
    for (int i = 0; i < (int)Q.size(); i++){
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1){
            left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		}
        if (left1 > -EPS){
            P.push_back(Q[i]); // Q[i] is on the left of ab
		}
        if (left1 * left2 < -EPS){
			// edge (Q[i], Q[i+1]) crosses line ab
            P.push_back(polygonLineIntersectSeg(Q[i], Q[i+1], a, b));
		}
    }
    if (!P.empty() && !(P.back() == P.front())){
        P.push_back(P.front()); // make P’s first Point = P’s last Point
	}
    return P;
}

double dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

double angle(Point a, Point o, Point b){
	// returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
// returns true if point p is in either convex/concave polygon P
bool inPolygon(Point pt, const vector<Point> &P) {
    /// on the line will also return true
    int ontheline = 0;
    if ((int)P.size() == 0){
        return false;
    }
    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if( fabs(dist(pt,P[i])+ dist(pt,P[i+1]) - dist(P[i],P[i+1]))< EPS   ){
            ontheline = 1;
        }
        if (ccw(pt, P[i], P[i+1])){
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        }else{
            sum -= angle(P[i], pt, P[i+1]);
        } // right turn/cw

    }
    return (fabs(fabs(sum) - 2*acos(-1)) < EPS || ontheline);
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
int main(){
    long long int caseCounter = 1;
    double n,w,h,x,y,x1,y1,x2,y2,area;
    pair<vector<Point>, vector<Point> > pp;
    while(cin >> n >> w >> h >> x >> y){
        vector<Point>poly,myPoly1, myPoly2;
        Point p(x,y);
        poly.push_back(Point(0,0));
        poly.push_back(Point(w,0));
        poly.push_back(Point(w,h));
        poly.push_back(Point(0,h));
        poly.push_back(poly[0]);
        for(int i=0;i<n;i++){
            cin >> x1 >> y1 >> x2 >> y2;
            myPoly1 = cutPolygon(Point(x1,y1), Point(x2,y2), poly);
            myPoly2 = cutPolygon(Point(x2,y2), Point(x1,y1), poly);
            if(inPolygon(Point(x,y), myPoly1)){
                poly = myPoly1;
            }else{
                poly = myPoly2;
            }
        }
        area = polygonArea(poly);
        printf("Case #%lld: %.3f\n",caseCounter++, area);

    }
    return 0;
}
