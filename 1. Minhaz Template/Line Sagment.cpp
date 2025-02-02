#include <iostream>
using namespace std;

#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
// line segment
// A C++ program to check if two given line segments intersect
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
void outputCheck(bool a){
    a== 1? cout << "Yes" << endl : cout << "NO" << endl;
}
int main()
{
	struct Point p1 = {1, 1}, q1 = {10, 1};
	struct Point p2 = {1, 2}, q2 = {10, 2};

	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {10, 0}, q1 = {0, 10};
	p2 = {0, 0}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {-5, -5}, q1 = {0, 0};
	p2 = {1, 1}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	Point p00 = {0,0}, p100 = {10,0}, p50 = {5,0}, p20 = {2,0}, p1010 = {10,10};

	Line l1 = {p00, p50}, l2 = {p20, p100};
	outputCheck(doIntersect(l1,l2));
	outputCheck(doIntersect(makeLine(0,0,5,0),makeLine(8,0,10,0)));
	outputCheck(doIntersect(makeLine(0,0,5,0),makeLine(10,5,10,-5)));

/*

2 : 2 : 1 : 1
No
2 : 1 : 1 : 2
Yes
0 : 0 : 0 : 0
No
0 : 0 : 0 : 0
Yes
0 : 0 : 0 : 0
NO
2 : 1 : 1 : 1
NO

*/
	return 0;
}
