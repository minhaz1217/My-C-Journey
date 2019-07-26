/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-833
Date : 26 / July / 2019
Comment: easy problem but hard to implement.
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
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}
struct Line{
    double a, b, c;
    Point lp,rp;
    Line(){}
    Line(Point p1, Point p2){
        if (fabs(p1.x - p2.x) < EPS){
            a = 1.0;
            b = 0.0;
            c = -p1.x; // default values
        }else{
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0; // IMPORTANT: we fix the value of b to 1.0
            c = -(double)(a * p1.x) - p1.y;
        }
        if(p1.x > p2.x){
            swap(p1,p2);
        }
        lp = p1;
        rp = p2;
    }
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
double pointToLineDistance(Point p, Line l){
    return ( abs(l.a*p.x +l.b*p.y + l.c )/ sqrt( l.a*l.a + l.b*l.b ) );
}

void show(Line mnLine){
    msg3(mnLine.lp.x, mnLine.lp.y, mnLine.rp.x, mnLine.rp.y)
}
void show(Point p){
    msg(p.x,p.y)
}
bool isEqual(double a , double b){
    return ( fabs( (a-b) )<EPS );
}
int main(){
    Point p1, p2, pp;
//    line lt;
//    pointsToLine( Point(0,0), Point(10,0),lt );
//    msg("L", pointToLineDistance(Point(5,5), lt  ) )
    long long int tc,n,caseCounter = 1;
    double a,b,c,d;
    cin>>tc;
    while(tc--){
        if(caseCounter>1){
            cout << endl;
        }
        cin >> n;
        vector<Line>lines;
        vector<Point>points;
        Line defaultLine;
        pointsToLine(Point(0,0), Point(1000000,0), defaultLine);
        lines.push_back(defaultLine);
        while(n--){
            cin >> a >> b >> c >> d;
            Line l;
            pointsToLine({a,b}, {c,d}, l);
            lines.push_back(l);
        }
        cin >> n;
        while(n--){
            cin >> pp.x >> pp.y;
            while(1){
                Line mnLine;
                double mn = INT_MAX*1.0;
                for(int i=0;i<lines.size();i++){
                    Line l = lines[i];
                    if(orientation(l.lp, l.rp, pp) == 2){
                        if(pp.x>=l.lp.x && pp.x<=l.rp.x){
                            double dist = pointToLineDistance(pp, l);
                            //msg(mn,dist)
                            if(mn > dist ){
                                ///msg(i, dist)
                                mn = dist;
                                mnLine = l;
                            }

                        }

                    }
                }
                if( isEqual(mnLine.a, defaultLine.a) && isEqual(mnLine.b, defaultLine.b) && isEqual(mnLine.c, defaultLine.c) ){
                    break;
                }
                if(mnLine.lp.y<mnLine.rp.y){
                    pp = mnLine.lp;
                }else{
                    pp = mnLine.rp;
                }
            }
            cout << pp.x << endl;
        }
        caseCounter++;
    }
    return 0;
}
