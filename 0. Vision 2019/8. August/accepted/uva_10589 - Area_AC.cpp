/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10589
Date : 11 / August / 2019
Comment: easy problem.
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

double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool isPointInsideCircle(Point center, double radius, Point p){
    if(pointDistance(center, p) <= radius){
        return true;
    }
    return false;
}
int main(){
    double n,a,m,x,y;
    while(cin >> n >> a){
        if(n==0 && a == 0){
            break;
        }
        Point A(0.0,0.0), B(a,0.0), C(a,a),D(0.0,a);
        m = 0;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            Point p(x,y);
            if( isPointInsideCircle(A,a,p) && isPointInsideCircle(B,a,p) && isPointInsideCircle(C,a,p) && isPointInsideCircle(D,a,p) ){
                m++;
            }
        }
        printf("%.5f\n", m*a*a/n);
    }
    return 0;
}
