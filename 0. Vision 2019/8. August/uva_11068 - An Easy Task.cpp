/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11068
Date : 02 / August / 2019
Comment: very easy problem. just had to be careful about the equations' corner case.
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
bool areParallel(Line l1, Line l2) { // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(Line l1, Line l2) { // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
bool areIntersect(Line l1, Line l2, Point &p) {
    //show(p);
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
    //show(p);
    return true;
}

bool lineFromConstants(double a, double b , double c, Line &l){

    if(a ==0 && b ==0){
        return false;
    }
    Point P1,P2;
    if(a== 0){
        P1 = Point(0,-c/b);
        P2 = Point(5, -c/b);
    }else if(b == 0){
        P1 = Point(-c/a, 0);
        P2 = Point(-c/a, 5);
    }else{
        P1 = Point(0,-c/b);
        P2 = Point(-c/a,0);
    }
    pointsToLine(P1,P2, l);
    return true;
}
int main(){
    double a,b,c,d,e,f;
    while(1){
        cin >> a >> b >> c >> d >> e >>f;
        if(!a && !b && !c && !d && !e && !f){
            break;
        }
        Line l1, l2;
        //msg(lineFromConstants(a,b,c,l1), lineFromConstants(d,e,f,l2) )
        Point p(0,0);
        if(!lineFromConstants(a,b,c,l1) || !lineFromConstants(d,e,f,l2)){
            printf("No fixed point exists.\n");
        }
        else if(areIntersect(l1,l2,p)){
            //show(p);
            printf("The fixed point is at %.2f %.2f.\n", p.x*-1.0, p.y*-1.0);
        }else{
            printf("No fixed point exists.\n");
        }
    }
    return 0;
}
