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
    Point()
    {
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
};
struct line{
    double a, b, c;
};
void pointsToLine(Point p1, Point p2, line &l){
    if (fabs(p1.x - p2.x) < EPS){
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x; // default values
    }else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}
bool areParallel(line l1, line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, Point &p) {
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
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
double dist(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main(){
    line l1,l2;
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
