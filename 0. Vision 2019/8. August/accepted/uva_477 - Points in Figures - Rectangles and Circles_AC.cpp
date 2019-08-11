/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-477
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

struct Rect{
    double l,r,t,b;
    Rect(){}
    Rect(double _l, double _r, double _t, double _b):l(_l),r(_r),t(_t),b(_b){}
};
struct Circle{
    double x,y,r;
    Circle(){}
    Circle(double _x, double _y, double _r):x(_x), y(_y), r(_r){}
};
bool pointInsideRect(Rect r, Point p ){
    if( p.x > r.l && p.x<r.r && p.y < r.t && p.y > r.b ){
        return true;
    }else{
        return false;
    }
}
double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool pointInsideCircle(Circle c, Point p){
    if(pointDistance(Point(c.x,c.y),p) <= c.r ){
        return true;
    }
    return false;
}


int main(){
    double l,r,b,t,x,y;
    char c;
    int flag,mainFlag,caseCounter = 1;
    vector<pair<char,long long int> >vec;
    vector<Rect>rects;
    vector<Circle>circles;
    while(cin >> c){
        if(c == '*'){
            break;
        }
        if(c == 'r'){
            cin >> l >> t >> r >> b;
            rects.push_back(Rect(l,r,t,b));
            vec.push_back(make_pair(c, rects.size()-1));
        }else if(c == 'c'){
            cin >> l >> b >> r;
            circles.push_back(Circle(l,b,r));
            vec.push_back(make_pair(c, circles.size()-1));
        }
    }
    caseCounter = 1;
    while(1){
        cin >> x >> y;
        if(x == 9999.9 && y == 9999.9){
            break;
        }
        mainFlag = 0;
        for(int i=0;i<vec.size();i++){

            c = vec[i].first;
           /// msg(i,c)
            flag = 0;
            if(c == 'r'){
                if(pointInsideRect(rects[ vec[i].second ], Point(x,y))){
                    flag = 1;
                }
            }else if(c == 'c'){
                if(pointInsideCircle(circles[ vec[i].second ], Point(x,y))){
                    flag = 1;
                }
            }
            if(flag == 1){
                printf("Point %d is contained in figure %d\n", caseCounter, i+1);
                mainFlag = 1;
            }
        }
        if(mainFlag == 0){
            printf("Point %d is not contained in any figure\n", caseCounter);
        }
        caseCounter++;
    }
    return 0;
}
