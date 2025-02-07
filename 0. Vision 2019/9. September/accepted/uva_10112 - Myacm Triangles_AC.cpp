/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10112
Date : 01 / September / 2019
Comment: very easy problem to implement as the boundary is lower.
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

bool cmp(Point a,Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}


struct vec{
    double x, y; // name: �vec� is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(Point a, Point b){
	// convert 2 Points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
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


void convexHullCo(vector<Point>& a) {
    /// generates a CLOCKWISE polygon.
    // gives right answer for collinear points.
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
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
/// CONVEX HULL 2 END
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}


int main(){

    double n,x,y,currArea, area,flag,a,b,c;
    char C;
    while(cin >> n){
        if(n==0){
            break;
        }
        vector<Point>mainPoly;
        for(int i=0;i<n;i++){
            cin >> C >> x >> y;
            mainPoly.push_back(Point(x,y));
        }
        currArea= INT_MIN;
        for(int i=0;i<mainPoly.size();i++){
            for(int j=i+1;j<mainPoly.size();j++){
                for(int k=j+1;k<mainPoly.size();k++){
                    vector<Point>poly;
                    poly.push_back(mainPoly[i]);
                    poly.push_back(mainPoly[j]);
                    poly.push_back(mainPoly[k]);
                    convexHullCo(poly);
                    poly.push_back(poly[0]);
                    area = polygonArea(poly);
                    if(area > currArea){
                        flag = 1;
                        for(int m=0;m<mainPoly.size();m++){
                            if( !(m == i || m == j || m == k) ){
                                if(inPolygon(mainPoly[m], poly)){
                                    flag = 0;
                                    break;
                                }
                            }
                        }
                        if(flag == 1){
                            currArea= area;
                            a = i;
                            b = j;
                            c = k;
                        }
                    }
                }
            }
        }
        cout << (char)(a+'A')<<(char)(b+'A')<< (char)(c+'A')<<endl;
        //msg2(a+'A',b+'A',c+'A')
    }
    return 0;
}
