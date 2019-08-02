/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11343
Date : 02 / August / 2019
Comment: easy problem solved with template.
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
    Point()
    {
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
    //msg3(o1,o2,o3,o4)
	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false; // Doesn't fall in any of the above cases
}

// Driver program to test above functions
struct Line{
    Point a,b;
    Line(){}
    Line(Point _a, Point _b): a(_a), b(_b){}

};
Line makeLine(int a, int b , int c , int d){
    Point p = {a,b}, q = {c,d};
    Line l = {p,q};
    return l;
}

bool doIntersect(Line a, Line b){
    return doIntersect(a.a, a.b, b.a,b.b);
}

int main(){
    long long int tc,n,counter;
    double a,b,c,d;
    cin >> tc;
    while(tc--){
        vector<Line>lines;
        cin >> n;
        vector<int>visited(n+1, 0);
        for(int i=0;i<n;i++){
            cin >> a >> b >> c >> d;
            lines.push_back(makeLine(a,b,c,d));
        }
        counter = 0;
        for(int i=0;i<lines.size();i++){
            for(int j=i+1;j<lines.size();j++){
                if(doIntersect(lines[i],lines[j])){
                    visited[i] = 1;
                    visited[j]=1;
                    counter++;
                }
            }
        }
        counter = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                counter++;
            }
        }
        cout << counter << endl;
        //cout << counter << endl;
    }
    return 0;
}
