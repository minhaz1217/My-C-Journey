/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11505
Date : 02 / August / 2019
Comment: just work with the polar coordinate. previous failed maybe because I was using bc instead of bk. also this time didn't use round and checked for RT.
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
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
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
int main(){

    long long int tc,n,a;
    string str;
    double x,y;
    cin >> tc;
    while(tc--){
        cin >> n;
        double degree= 0.0;
        x = 0.0;
        y = 0.0;
        while(n--){
            cin >> str >> a;
            if(str == "fd"){
                x = x + a*cos( DEG_to_RAD(degree) );
                y = y + a*sin( DEG_to_RAD(degree) );
                //msg(x,y)
            }else if(str == "bk"){
                x = x - a*cos( DEG_to_RAD(degree) );
                y = y - a*sin( DEG_to_RAD(degree) );
            }else if(str == "lt"){
                degree += a;
            }else if(str == "rt"){
                degree -= a;
            }
        }
        printf("%.0f\n", pointDistance(Point(0,0), Point(x,y)));
        //cout << round(pointDistance(Point(0,0), Point(x,y))) << endl;
    }

    return 0;
}
