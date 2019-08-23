/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 11 / August / 2019
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

struct Rect{
    double l,r,t,b;
    Rect(){}
    Rect(double _l, double _r, double _t, double _b):l(_l),r(_r),t(_t),b(_b){}
};
bool pointInsideRect(Rect r, Point p ){
    if( p.x >= r.l && p.x<=r.r && p.y <= r.t && p.y >= r.b ){
        return true;
    }else{
        return false;
    }
}

bool isInside(double al, double ar, double bl,double br){
    // checks if a is inside linesegment b
    if(al >= bl && ar <= br){
        return true;
    }
    return false;
}

Rect commonRect(Rect a, Rect b){
    vector<double> x,y;
    x.push_back(a.l);
    x.push_back(a.r);
    x.push_back(b.l);
    x.push_back(b.r);
    y.push_back(a.b);
    y.push_back(a.t);
    y.push_back(b.b);
    y.push_back(b.t);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    Rect r(-1,-1,-1,-1);
    for(int i=1;i<x.size();i++){

        if( isInside(x[i-1], x[i], a.l, a.r) && isInside(x[i-1], x[i], b.l, b.r) ){
            if(r.l == -1){
                r.l = x[i-1];
                r.r = x[i];
            }else{
                r.r = x[i];
            }
        }
    }
    for(int i=1;i<y.size();i++){
        if( isInside(y[i-1], y[i], a.b, a.t) && isInside(y[i-1], y[i], b.b, b.t) ){
            if(r.b == -1){
                r.b = y[i-1];
                r.t = y[i];
            }else{
                r.t = y[i];
            }
        }
    }

    return r;
}


Rect commonRectSmall(Rect a, Rect b){
    Rect r;
    r.l = max(a.l,b.l);
    r.r = min(a.r,b.r);
    r.b = max(a.b,b.b);
    r.t = min(a.t,b.t);
    if(r.l > r.r || r.b > r.t){
        r = Rect(-1,-1,-1,-1);
    }
    return r;
}
void show(rect r){
    msg3(r.l,r.r,r.t,r.b)
}
int main(){

    return 0;
}
