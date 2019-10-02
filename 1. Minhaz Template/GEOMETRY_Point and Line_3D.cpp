/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 26 / July / 2019
Comment: POINT AND LINE 3D
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
struct Point3d{
    double x, y, z;
    Point3d(){
        x = y = z = 0.0;
    }
    Point3d(double _x, double _y, double _z):x(_x), y(_y),z(_z) {}
    bool operator == (Point3d other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS) &&(fabs(z - other.z) < EPS) );
    }
    bool operator < (Point3d other) const {
        if (fabs(x - other.x) > EPS){
                return x < other.x;
        }else if( fabs(y-other.y) > EPS ){
            return y <other.y;
        }else{
            return z<other.z;
        }
    }
};
struct Line3d{
    Point3d lp,rp;
    Line3d(){}
    Line3d(Point3d _a, Point3d _b){
        if(_a<_b){
            lp = _a;
            rp = _b;
        }else{
            lp = _b;
            rp = _a;
        }
    }
};
double pointDistance3d(Point3d a, Point3d b){
    return (double)sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z) );
}
double pointToLineDistance3d(Point3d p, Line3d l){
    double lineLength = pointDistance3d( l.lp,l.rp );
    double u, interX,interY,interZ;
    double px = p.x, py = p.y, pz = p.z, x1 = l.lp.x, y1 = l.lp.y, z1 = l.lp.z, x2 = l.rp.x , y2 = l.rp.y,z2=l.rp.z;

    u = ( (px - x1 )* (x2-x1) +
          (py - y1) * (y2-y1) +
          (pz - z2) * (z2-z1 ))/
          (lineLength * lineLength);
    if(u <0.0f || u > 1.0f){
        cc("NONE")
        return 0;
    }
    interX = x1 + u * (x2 - x1);
    interY = y1 + u * (y2 - y1);
    interZ = z1 + u * (z2 - z1);
    Point3d intersectPoint(interX, interY, interZ);
    double dist = pointDistance3d(intersectPoint, p);
    return dist;
}

struct Rect3d{
    Point3d bl, tr;
    Rect3d(){}
    Rect3d(Point3d _bl, Point3d _tr):bl(_bl), tr(_tr){}
};
Rect3d commonRect(Rect3d a, Rect3d b){
    Rect3d r;
    r.bl.x = max( a.bl.x,b.bl.x );
    r.bl.y = max( a.bl.y,b.bl.y );
    r.bl.z = max( a.bl.z,b.bl.z );

    r.tr.x = min( a.tr.x,b.tr.x );
    r.tr.y = min( a.tr.y,b.tr.y );
    r.tr.z = min( a.tr.z,b.tr.z );
    if( r.bl.x > r.tr.x || r.bl.y > r.tr.y || r.bl.z > r.tr.z ){
        r.bl = Point3d(-1,-1,-1);
        r.tr = Point3d(-1,-1,-1);
    }
    return r;
}
double rect3dArea(Rect3d r){
    return ( (r.tr.x-r.bl.x) * (r.tr.y-r.bl.y) * (r.tr.z-r.bl.z) );
}

int main(){
    double a,b,c,d,e,f;
    while(cin >> a >> b >> c >> d >> e >> f){
        msg2(a,b,c)
        msg2(d,e,f)
        msg("DIST", pointToLineDistance3d( Point3d(d,e,f), Line3d( Point3d(a,b,c), Point3d(0,0,100) ) ))
    }
    return 0;
}
