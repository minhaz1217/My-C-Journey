/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10927
Date : 26 / July / 2019
Comment: couldn't make the n2 to n, solved using https://vjp.ti12z.cn/source/19694628?e=1564257600&token=61yRQPiRfi8yXmLqUqOyPAkEDDQefVIIxiqs8pbr:jMoNM-MT1b0v3uW5ujnaNP29o1s=
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


struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
bool operator < (point other) const { // override less than operator
if (fabs(x - other.x) > EPS) // useful for sorting
return x < other.x; // first criteria , by x-coordinate
return y < other.y; } // second criteria, by y-coordinate
// use EPS (1e-9) when testing equality of two floating points
bool operator == (point other) const {
return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
};
double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); } // return double


// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
double rad = (theta*acos(-1)/180.0); // multiply theta with PI / 180.0
return point(p.x * cos(rad) - p.y * sin(rad),
p.x * sin(rad) + p.y * cos(rad)); }

struct line { double a, b, c; };
// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
} else {
l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
l.c = -(double)(l.a * p1.x) - p1.y;
} }

bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
bool areSame(line l1, line l2) { // also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
else p.y = -(l2.a * p.x + l2.c);
return true; }

struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) { // convert 2 points to vector a->b
return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
return vec(v.x * s, v.y * s); } // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
return point(p.x + v.x , p.y + v.y); }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
c = translate(a, scale(ab, u)); // translate a to c
return dist(p, c); } // Euclidean distance between p and c

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
if (u < 0.0) { c = point(a.x, a.y); // closer to a
return dist(p, a); } // Euclidean distance between p and a
if (u > 1.0) { c = point(b.x, b.y); // closer to b
return dist(p, b); } // Euclidean distance between p and b
return distToLine(p, a, b, c); } // run distToLine as above

double angle(point a, point o, point b) { // returns angle aob in rad
vec oa = toVec(o, a), ob = toVec(o, b);
return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
return cross(toVec(p, q), toVec(p, r)) > 0; }
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    double n,x,y,z,distp,distq,ww,w,flag,mx,slope1,slope2,h1,h2;
    point p1,p2;
    long long int caseCounter = 1;
    while(1){
        cin >> n;
        if(n==0){
            break;
        }
        vector< pair<double, pair<point , double> > >points, quad[4];
        vector< point > rejected;
        point origin(0,0);
        while(n--){
            cin >> x >> y >> z;

            points.push_back(make_pair( atan2(y,x), make_pair(point(x,y),z )));
        }
        sort(points.begin(),points.end());
        //reverse(points.begin(),points.end());
        mx = points[0].second.second;
        for(int i=1;i<points.size();i++){
            slope1 = points[i].first;
            slope2 = points[i-1].first;
            h1 = points[i].second.second;
            h2 = points[i-1].second.second;
            p1 = points[i].second.first;
            p2 = points[i-1].second.first;
            if(slope1 == slope2){
                if(h1 <= mx){
                    rejected.push_back(p1);
                }
                mx = max(mx, h1);
            }else{
                mx = h1;
            }
        }
        sort(rejected.begin(),rejected.end());
        cout << "Data set "<< caseCounter++ <<":" << endl;
        if(rejected.size() == 0){
            cout << "All the lights are visible." <<endl;
        }else{
            cout << "Some lights are not visible:" << endl;
            for(int i=0;i<rejected.size()-1;i++){
                cout << "x = "<< rejected[i].x << ", y = "<< rejected[i].y <<";" << endl;
            }
                cout << "x = "<< rejected[rejected.size()-1].x << ", y = "<< rejected[rejected.size()-1].y <<"." << endl;

        }

    }
    return 0;
}
