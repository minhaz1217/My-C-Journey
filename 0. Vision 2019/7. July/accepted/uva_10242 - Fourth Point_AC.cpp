/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10242
Date : 29 / July / 2019
Comment: 3 hours running, on this single problem. 1.42 AM.
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

double angleBetweenPoints(Point a, Point b , Point c){
    /*   a
       /
      /
     b ----- c
    */
    double ab = pointDistance(a,b), bc = pointDistance(b,c), ac = pointDistance(a,c);
    return acos( (bc*bc  + ab*ab - ac*ac)/(2.0*bc*ab) ); // will return the value in radian.

}
double radToDegree(double rad){
    return rad*180.0/acos(-1);
}
double degreeToRad(double deg){
    return (deg*acos(-1))/180.0;
}
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
double RAD_to_DEG(double rad){
    return rad*180.0 / acos(-1);
}
Point rotate(Point p, double theta) {
    // rotating (5,0) 180 degree produces (-5,0)
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
int orientation(Point p, Point q, Point r)
{
	// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
	// for details of below formula.
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}


double angleBetweenPoints(Point a, Point b , Point c){
    /*   a
       /
      /
     b ----- c
    */
    double ab = pointDistance(a,b), bc = pointDistance(b,c), ac = pointDistance(a,c);
    return acos( (bc*bc  + ab*ab - ac*ac)/(2.0*bc*ab) ); // will return the value in radian.

}
Point rotateAroundPoint(Point p, Point rotateAround, double degree){ // degree in degree
    Point d = rotate(Point(p.x-rotateAround.x, p.y-rotateAround.y), degree);
    d.x += rotateAround.x;
    d.y += rotateAround.y;
    return d;
}
Point changeLineLength( Point p1, Point p2, double sz ){
    double n = sz;
    double D = pointDistance(p1,p2);
    Point p;
    p.x = ((p2.x -p1.x)*n) / D + p2.x;
    p.y = ((p2.y -p1.y)*n) / D + p2.y;
//    p.y = ((1.0-n/D)*p1.y + (n/D)*p2.y);
    return p;
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
    Point a(0,0),b(0,1),c(1,1),a1, nl(0,0);
    double t1,t2,cd,da,ab,bc;
    Point d;

    while(cin >> a1.x >> a1.y ){
            int found = 0;
        vector<Point>vec;
        map<Point, int>mp;
        vec.push_back(a1);
        mp[a1] = 1;
        a = nl;
        b = nl;
        c = nl;
        for(int i=0;i<3;i++){
            cin >> a1.x >> a1.y;
            //show(a1);
            if(mp.find(a1) == mp.end()){
                mp[a1] = 1;
            }else{
                b = a1;
            }
            vec.push_back(a1);
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<4;i++){
            if(a == nl && !(b== vec[i])){
                a = vec[i];
            }else if(c == nl && !(b == vec[i])){
                c = vec[i];
            }
        }
//        show(a);
//        show(b);
//        show(c);
        t1 = RAD_to_DEG(angleBetweenPoints(b,a,c));
        t2 = RAD_to_DEG(angleBetweenPoints(b,c,a));

        for(double i=0;i<=3;i+=1){

            bc = pointDistance(b,c);
            ab = pointDistance(a,b);
            double len = ab-bc;
//            cc(len)
            Point nwB = changeLineLength(a,b, -len);
            d = rotateAroundPoint( nwB, a,(t1+t2)+i*90);
            cd = pointDistance(d,c);
            da = pointDistance(d,a);
//            msg3(ab,bc,cd,da)
            if( fabs(cd-ab) <EPS && fabs(da-bc)<EPS ){
                found = 1;
                break;
            }
        }
        if(found == 0){
            swap(a,c);
            for(double i=0;i<=3;i+=1){

                bc = pointDistance(b,c);
                ab = pointDistance(a,b);
                double len = ab-bc;
    //            cc(len)
                Point nwB = changeLineLength(a,b, -len);
                d = rotateAroundPoint( nwB, a,(t1+t2)+i*90);
                cd = pointDistance(d,c);
                da = pointDistance(d,a);
    //            msg3(ab,bc,cd,da)
                if( fabs(cd-ab) <EPS && fabs(da-bc)<EPS ){
                    found = 1;
                    break;
                }
            }
        }
        //msg("F", found)
        clean(d);

        printf("%.3f %.3f\n",d.x,d.y);
    }
    return 0;
}
