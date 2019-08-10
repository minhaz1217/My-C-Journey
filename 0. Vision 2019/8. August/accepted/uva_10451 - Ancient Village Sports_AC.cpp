/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10451
Date : 10 / August / 2019
Comment: easy equations.
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

double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
#define PI acos(-1)
int main(){
    double n,a,r,s,inCircle,outCircle,inCircleR,outCircleR;
    int caseCounter = 1;
    while(1){
        cin >> n >> a;
        if(n<3){
            break;
        }
        r = sqrt( (2.0*a) / ( n * sin( DEG_to_RAD(360.0/n) ) ) );
        s = 2.0*r * sin( DEG_to_RAD(180.0/n) );
        inCircleR =  (s / tan( DEG_to_RAD(180.0/n) ))/2.0;
        outCircleR = (s / sin( DEG_to_RAD(180.0/n) ) )/2.0;
        inCircle = PI * inCircleR*inCircleR;
        outCircle = PI * outCircleR*outCircleR;
        //msg3(r,.5*n*r*r*sin( DEG_to_RAD(360.0/n) ),inCircle, outCircle)
        printf("Case %d: %.5f %.5f\n",caseCounter++, outCircle- a,a-inCircle);
    }
    return 0;
}
