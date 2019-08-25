/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 23 / August / 2019
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
vec scale(vec v, double s){
	// nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s);
} // shorter.same.longer
Point translate(Point p, vec v){
	// translate p according to v
    return Point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}
// returns the distance from p to the line defined by
// two Points a and b (a and b must be different)
// the closest Point is stored in the 4th parameter (byref)
double distToLine(Point p, Point a, Point b, Point &c){
	// formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c);
}
// Euclidean distance between p and c
// returns the distance from p to the line segment ab defined by
// two Points a and b (still OK if a == b)
// the closest Point is stored in the 4th parameter (byref)
double distToLineSegment(Point p, Point a, Point b, Point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0){
        c = Point(a.x, a.y); // closer to a
        return dist(p, a);
    } // Euclidean distance between p and a
    if (u > 1.0){
        c = Point(b.x, b.y); // closer to b
        return dist(p, b);
    } // Euclidean distance between p and b
    return distToLine(p, a, b, c);
} // run distToLine as above

double angle(Point a, Point o, Point b){
	// returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}
// note: to accept collinear Points, we have to change the ‘> 0’
// returns true if Point r is on the left side of line pq
bool ccw(Point p, Point q, Point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
// returns true if Point r is on the same line as the line pq
bool collinear(Point p, Point q, Point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

/// POLYGON START
// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double polygonPerimeter(const vector<Point> &P){
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++){
		// remember that P[0] = P[n-1]
        result += dist(P[i], P[i+1]);
	}
    return result;
}
double polygonArea(const vector<Point> &P)
{
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

/// needs CROSS, toVec
bool polygonCollinear(Point p, Point q, Point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}




bool polygonIsConvex(const vector<Point> &P){
	// returns true if all three
    int sz = (int)P.size(); // consecutive vertices of P form the same turns
    if (sz <= 3){
        return false; // a Point/sz=2 or a line/sz=3 is not convex
	}
    bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
    for (int i = 1; i < sz-1; i++){
		// then compare with the others
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft){
            return false; // different sign -> this polygon is concave
		}
	}
    return true;
}

// line segment p-q intersect with line A-B.
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

Point pivot(0, 0);
bool angleCmp(Point a, Point b){
	// angle-sorting function
    if (collinear(pivot, a, b)){
		// special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
	}
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} // compare two angles

vector<Point> convexHull(vector<Point> P){
// the content of P may be reshuffled
	int i, j, n = (int)P.size();
    if (n <= 3){
        if (!(P[0] == P[n-1])){
            P.push_back(P[0]); // safeguard from corner case
		}
        return P;
    } // special case, the CH is P itself
// first, find P0 = Point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++){
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)){
            P0 = i;
		}
	}
    Point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp; // swap P[P0] with P[0]
// second, sort Points by angle w.r.t. pivot P0
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
// to be continued
// continuation from the earlier part
// third, the ccw tests
    vector<Point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n){// note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])){
            S.push_back(P[i++]); // left turn, accept
		}else{
            S.pop_back();
		}
    } // or pop the top of S until we have a left turn
    return S;
}
int main(){
    double n,x,y;
    while(1){
        cin >> n;
        vector<Point>vec;
        while(n--){
            cin >> x >> y;
            vec.push_back(Point(x,y));
        }
        //vec.push_back(vec[0]);
        cout << polygonArea(convexHull(vec)) << endl;
    }
    return 0;
}
