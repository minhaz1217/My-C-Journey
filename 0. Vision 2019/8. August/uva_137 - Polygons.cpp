/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-137
Date : 24 / August / 2019
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
double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}
bool collinear(Point p, Point q, Point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
/// line segment p-q intersect with line A-B.
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
    // cutting a polygon with a line generates 2 polygons, left and right polygon
    vector<Point> P,R;
    for (int i = 0; i < (int)Q.size(); i++){
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1){
            left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		}
        if (left1 > -EPS){
            P.push_back(Q[i]); // Q[i] is on the left of ab
		}else{
		    R.push_back(Q[i]);
		}
        if (left1 * left2 < -EPS){
			// edge (Q[i], Q[i+1]) crosses line ab
			Point newPoint = polygonLineIntersectSeg(Q[i], Q[i+1], a, b);
            P.push_back(newPoint);
            R.push_back(newPoint);
		}

    }
    if (!P.empty() && !(P.back() == P.front())){
        P.push_back(P.front()); // make P’s first Point = P’s last Point
	}
    if (!R.empty() && !(R.back() == R.front())){
        R.push_back(R.front()); // make P’s first Point = P’s last Point
	}
    return P; // we just return the left half.
}

/// CONVEX HULL START
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
bool ccw(Point p, Point q, Point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
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
    double n,x,y,x1,x2;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }

        vector<Point>poly1, poly2;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            poly1.push_back(Point(x,y));
        }
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            poly2.push_back(Point(x,y));
        }
        poly1.push_back(poly1[0]);
        poly2.push_back(poly2[0]);
        poly1 = convexHull(poly1);
        poly2 = convexHull(poly2);
        vector<Point>newVec;

//        cout << endl << "Poly 1" << endl;
        for(int i=1;i<poly1.size();i++){
            x1 = min(poly1[i].x, poly1[i-1].x);
            //printf(" (%f,%f)", poly1[i].x,poly1[i].y);
        }
        vector<Point>leftPoly, rightPoly;

//        cout << endl << "Poly 2" << endl;
        for(int i=1;i<poly2.size();i++){
            x2 = min(poly2[i].x, poly2[i-1].x);
            //printf(" (%f,%f)", poly2[i].x,poly2[i].y);
        }
        if(x1<x2){
            leftPoly = poly1;
            rightPoly = poly2;
        }else{
            leftPoly = poly2;
            rightPoly = poly1;
        }

        for(int i=0;i<leftPoly.size();i++){
//            x2 = min(poly2[i].x, poly2[i-1].x);
            printf(" (%f,%f)", leftPoly[i].x,leftPoly[i].y);
        }

        for(int i=1;i<rightPoly.size();i++){
            leftPoly = cutPolygon(rightPoly[i], rightPoly[i-1], leftPoly);

           int t = i;
           msg("ITERATION", t)
            for(int i=0;i<leftPoly.size();i++){
    //            x2 = min(poly2[i].x, poly2[i-1].x);
                printf(" (%f,%f)", leftPoly[i].x,leftPoly[i].y);
            }
            i = t;
        }
        for(int i=0;i<leftPoly.size();i++){
//            x2 = min(poly2[i].x, poly2[i-1].x);
            printf(" (%f,%f)", leftPoly[i].x,leftPoly[i].y);

        }
        cout << polygonArea(leftPoly) << endl;
    }

    return 0;
}
