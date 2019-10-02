/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-858
Date : 01 / September / 2019
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
double dist(Point p1, Point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

Point intersectingLineSegment(Point p, Point q, Point A, Point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return Point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

bool isPointOnTheLine(Point a, Point b, Point p){
    if(dist(a,b) == dist(a,p)+dist(b,p)){
        return true;
    }else{
        return false;
    }
}
int main(){
    long long int tc,n,counter,t;
    double x,y,sum;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<Point>poly;
        vector<double>Y;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            poly.push_back(Point(x,y));
        }
        counter = 0;
        cin >> t >> x;
        //sort(poly.begin(),poly.end());
        poly.push_back(poly[0]);

        for(int i=1;i<poly.size();i++){
            Point p;
                //msg2(counter,poly[i-1].x, poly[i].x)

                p = intersectingLineSegment(poly[i-1], poly[i], Point(x,1e9), Point(x,-1e9));
                //if(isPointOnTheLine(poly[i-1], poly[i], p)){
                //    msg2(i, p.x,p.y)
                    Y.push_back(p.y);
               // }

        }
        sort(Y.begin(), Y.end());
        sum = 0;
        for(int i=1;i<Y.size();i++){
            //msg(Y[i-1], Y[i])
            sum += Y[i] - Y[i-1];
            //sum += fabs(Y[i].first-Y[i-1].first);
        }
        msg("SUM", sum)
        //msg(counter, t)
        if(sum>=t){
            cout <<"YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
