/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://uva.onlinejudge.org/external/118/11800.pdf
Date : 12 / August / 2019
Comment: the points are given randomly so the a > b > c > d, relations of a quartile is hard to maintain. WA : if 2 points are same, then they are trapezium. 2nd WA: Slope function was wrong, it shouldn't have abs.
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


double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
int orientation(Point p, Point q, Point r)
{
	/// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear

	return (val > 0)? 1: 2; /// clock or counterclock wise
}
double angleBetweenPoints(Point a, Point b , Point c){
    /*   a
       /
      /
     b ----- c
    */
    double ab = pointDistance(a,b), bc = pointDistance(b,c), ac = pointDistance(a,c);
    return acos( (bc*bc  + ab*ab - ac*ac)/(2.0*bc*ab) ) * 180.0 / acos(-1) ;

}
double slope(Point a, Point b){
    if(a.x == b.x){
        /// the line is vertical, so slope is infinite. we avoid 0 value
        return INT_MAX;
    }
    return ( (a.y-b.y)/(a.x-b.x) );
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
int main(){
    double tc,x1,y1,x2,y2,x3,y3,x4,y4,ab,bc,cd,da;
    long long int caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << "Case " << caseCounter++ << ": ";
        Point p1(x1,y1), p2(x2,y2), p3(x3,y3), p4(x4,y4),a,b,c,d;

        if(orientation( p1, p2,p3 ) == orientation(p1,p2,p4)){
            a = p1;
            b = p2;
            c = p3;
            d = p4;
            if(orientation(b,c, d) != orientation(b,c,a)){
                swap(c,d);
            }
        }else{
            a = p1;
            b = p3;
            c = p2;
            d = p4;
            if(orientation(b,c, d) != orientation(b,c,a)){
                swap(c,d);
            }
        }
//        show(a);
//        show(b);
//        show(c);
//        show(d  );
        ab = pointDistance(a,b);
        bc = pointDistance(b,c);
        cd = pointDistance(c,d);
        da = pointDistance(d,a);
        if(ab == bc && bc == cd && cd == da){
            if( fabs(angleBetweenPoints(a,b,c)-90.0)< EPS){
                cout << "Square" << endl;
            }else{
                cout << "Rhombus" << endl;
            }
        }else if(ab == cd && bc == da){
            if( fabs(angleBetweenPoints(a,b,c)-90.0)< EPS){
                cout << "Rectangle" << endl;
            }else{
                cout << "Parallelogram" << endl;
            }
        }else{
//            msg2("1",slope(a,b), slope(c,d))
//            msg2("2",slope(b,c), slope(d,a))
//|| (a == b || b == c || c ==d || d ==a)
            if( fabs( slope(a,b)-slope(c,d) ) < EPS || fabs( slope(b,c)-slope(d,a) ) < EPS  ){
               cout << "Trapezium" << endl;
            }else{
                cout << "Ordinary Quadrilateral" << endl;
            }
        }
    }
    return 0;
}
