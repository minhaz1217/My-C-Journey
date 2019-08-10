/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10283
Date : 10 / August / 2019
Comment: hard to find the correct equation but it was very very fun.
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

#define PI acos(-1)

double triangleArea( double a, double b, double c ){
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}

double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
int main(){

    double R,r,n,al,th, segArea, triArea, blueArea,smallCircleArea,greenArea;
    while(cin >> R >> n){


        al = (n-2)*180.0/n;
        th = 360.0 /n;
        r = (R * sin(DEG_to_RAD(th)) ) / ( 2.0*sin( DEG_to_RAD( al/2 ) ) + sin( DEG_to_RAD(th)));
        segArea = PI * (r)*(r) * (al/2.0)/360.0;
        triArea = triangleArea(r+r, R-r, R-r);
        blueArea = (triArea - (segArea+segArea)) * n;
        smallCircleArea = PI * r*r;
        greenArea = (PI*R*R) - (smallCircleArea * n + blueArea);
        if(n == 1){
            blueArea = 0;
            greenArea = 0;
            r = R;
        }else if(n==2){
            r = R/2.0;
            blueArea = 0;
            greenArea = (PI*R*R) - 2.0*(PI *r *r);
        }

        printf("%.10f %.10f %.10f\n", r, blueArea, greenArea);
    }
    return 0;
}
