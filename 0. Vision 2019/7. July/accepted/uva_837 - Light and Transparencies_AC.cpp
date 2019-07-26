/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-837
Date : 26 / July / 2019
Comment: same as waterfall problem with a twist.
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

    long long int tc,n,caseCounter =1;
    double weight,a,b,c,d,w,mainDist;
    cin >> tc;
    while(tc--){
        cin >> n;
        if(caseCounter>1){
            cout << endl;
        }
        caseCounter++;
        vector<pair<Line, double> > lines;
        vector<pair<double, double> > points,output;
        Line defaultLine;
        pointsToLine(Point(-1000000,0), Point(1000000,0), defaultLine);
        lines.push_back(make_pair(defaultLine, 1));
        while(n--){
            cin >> a >> b >> c >> d >> w;
            Line l;
            pointsToLine( Point(a,b), Point(c,d),l );
            lines.push_back(make_pair(l,w));
            points.push_back(make_pair(a,b));
            points.push_back(make_pair(c,d));
        }
        sort(points.begin(), points.end());

        for(int i=0;i<points.size();i++){
            Point pp(points[i].first, points[i].second);
            mainDist = 1;
            //show(pp);
            for(int j=0;j<lines.size();j++){
                Line l = lines[j].first;
                weight = lines[j].second;
                if(pp.x>=l.lp.x && pp.x<l.rp.x){
                    /// the point is inside the line
                    mainDist *= weight;
                    //msg("INTER", weight)

                }
            }
            //msg(pp.x,mainDist)
            output.push_back(make_pair(pp.x, mainDist));
        }
        cout << output.size()+1 << endl;
        printf("-inf %.3f %.3f\n", output[0].first, 1.0);
        for(int i=0;i<output.size()-1;i++){
            printf("%.3f %.3f %.3f\n", output[i].first,output[i+1].first, output[i].second);
        }
        printf("%.3f +inf 1.000\n", output[output.size()-1].first);
        }
    return 0;
}
