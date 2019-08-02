/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11505
Date : 02 / August / 2019
Comment: solved after getting help. couldn't find the problem with my original solution.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

#define _USE_MATH_DEFINES


#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
typedef complex<double> point;
#define X real()
#define Y imag()
#define polar(r, t) (r) * exp(point(0,(t)))
#define rotate(v,t) (v) * exp(point(0,(t)))
#define length(v) hypot((v).Y , (v).X)



int main(){

    long long int tc,n;
    double a;
    _USE_MATH_DEFINES;
    string str;
    double x,y;
    cin >> tc;
    while(tc--){
        cin >> n;
        point p(0,0), d(1,0);
        while(n--){
            cin >> str >> a;
            if(str == "fd"){
                p = p + polar(a, 0) *d;
                //msg(x,y)
            }else if(str == "bk"){
                p = p  - polar(a, 0) *d;
            }else if(str == "lt"){
                d = rotate(d, a* 3.14159265358979323846/180.0);
            }else if(str == "rt"){
                d = rotate(d, -a* 3.14159265358979323846/180.0);
            }
        }
        printf("%.0f\n", length( p ));
        //cout << (int)round(pointDistance(Point(0,0), Point(x,y))) << endl;
    }

    return 0;
}
