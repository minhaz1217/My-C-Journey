/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-737
Date : 13 / August / 2019
Comment: easy problem if you can notice the similarity with 2d.
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
    double n,x,y,z,r;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        cin >> x >> y >> z >> r;
        Rect3d p(Point3d(x,y,z), Point3d(x+r, y+r, z+r));
        n--;
        while(n--){
            cin >> x >> y >> z >> r;
            Rect3d rr(Point3d(x,y,z), Point3d(x+r, y+r, z+r));
            p = commonRect(p,rr);
        }
        printf("%.0f\n", rect3dArea(p));
        //cout << rect3dArea(p) << endl;

    }
    return 0;
}
