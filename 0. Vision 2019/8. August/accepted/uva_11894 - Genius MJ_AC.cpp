/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11894
Date : 02 / August / 2019
Comment: just rotation and translation.
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
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
void clean(Point &p){
    if(fabs(p.x-0)<EPS){
        p.x = 0;
    }
    if(fabs(p.y-0)<EPS){
        p.y = 0;
    }
}
int main(){
    long long int tc,n,counter;
    double x,y,a,b;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<Point>lines1,lines2,lines3,lines4,lines;
        Point p1,p2,p3,p4;
        counter = 0;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            lines.push_back(Point(x,y)  );
            //mp[Point(x,y)] = 1;
        }

        sort(lines.begin(),lines.end());
        a = lines[0].x;
        b = lines[0].y;
        for(int i=0;i<lines.size();i++){
            lines[i].x -= a;
            lines[i].y -= b;
        }

        for(int i=0;i<n;i++){
            cin >> x >> y;
            p1 = rotate(Point(x,y), 0);
            p2 = rotate(Point(x,y), 90);
            p3 = rotate(Point(x,y), 180);
            p4 = rotate(Point(x,y), 270);
            lines1.push_back(p1);
            lines2.push_back(p2);
            lines3.push_back(p3);
            lines4.push_back(p4);
        }
        sort(lines1.begin(), lines1.end());
        sort(lines2.begin(), lines2.end());
        sort(lines3.begin(), lines3.end());
        sort(lines4.begin(), lines4.end());
        a = lines1[0].x;
        b = lines1[0].y;
        for(int i=0;i<lines1.size();i++){
            lines1[i].x -= a;
            lines1[i].y -= b;
        }

        a = lines2[0].x;
        b = lines2[0].y;
        for(int i=0;i<lines2.size();i++){
            lines2[i].x -= a;
            lines2[i].y -= b;
        }
        a = lines3[0].x;
        b = lines3[0].y;
        for(int i=0;i<lines3.size();i++){
            lines3[i].x -= a;
            lines3[i].y -= b;
        }
        a = lines4[0].x;
        b = lines4[0].y;
        for(int i=0;i<lines4.size();i++){
            lines4[i].x -= a;
            lines4[i].y -= b;
        }
        if(lines1 == lines || lines2 == lines || lines3 == lines || lines4 == lines){
            cout << "MATCHED" << endl;
        }else{
            cout << "NOT MATCHED" << endl;
        }
    }
    return 0;
}
