/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10005
Date : 08 / August / 2019
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
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const {
        if (fabs(x - other.x) > EPS)
                return x < other.x;
        return y < other.y;
    }
};
bool circle2PtsRad(Point p1, Point p2, double r, Point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0){
        return false;
    }
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}
double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
int main(){
    double n,a,mx,dist,x,y,radius,flag,r;
    int k,flag1,flag2;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        Point p1,p2;
        vector<Point>poly;
        vector<Point>vec;
        map<Point, int>mp;
        mx = INT_MIN;

        for(int i=0;i<n;i++){
            cin >> x >> y;
            Point p(x,y);
            poly.push_back(p);
        }
        sort(poly.begin(),poly.end());
        cin >> r;
        flag = 1;


        Point c1,c2;
        circle2PtsRad(poly[0],poly[poly.size()-1],r,c1);
        circle2PtsRad(poly[poly.size()-1],poly[0],r,c2);
        flag1 = 1;
        flag2 = 1;
        show(c1);
        show(c2);
        for(int i=0;i<poly.size();i++){
            if(pointDistance(poly[i], c1) > r){
                flag1 = 0;
            }
            if(pointDistance(poly[i],c2) > r){
                flag2  = 0;
            }
        }

        if( flag1 || flag2 ){
            cout << "The polygon can be packed in the circle." << endl;
        }else{
            cout << "There is no way of packing that polygon." << endl;
        }
    }

    return 0;
}
