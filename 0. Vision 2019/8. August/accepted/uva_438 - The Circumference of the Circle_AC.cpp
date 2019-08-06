/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-438
Date : 06 / August / 2019
Comment: discovered new equation solving this.
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

int main(){
    double x1,x2,x3,y1,y2,y3,g,f,c,r;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        //cout << x1 << ", " << y1 << "  " << x2 << ", " << y2 << "  " << x3 << ", " << y3 << endl;
        f = ( (x1*x1 - x3*x3)*(x1-x2) + (y1*y1 - y3*y3)*(x1-x2) + (x2*x2 - x1*x1)*(x1-x3) + (y2*y2 - y1*y1)*(x1-x3) )/
            ( (y3-y1)*(x1-x2) - (y2-y1)*(x1-x3) );
        f = f/2.0;
        double gupper = ( (x1*x1 - x3*x3)*(y1-y2)
                         + (y1*y1 - y3*y3)*(y1-y2)
                         + (x2*x2 - x1*x1)*(y1-y3)
                         + (y2*y2 - y1*y1)*(y1-y3) )
        ,glower = ( (x3-x1)*(y1-y2) - (x2-x1)*(y1-y3) );
        g = gupper/glower;
        g = g/2.0;
        c = (x1*x1)*-1 - (y1*y1) - 2.0*g*x1 - 2.0*f*y1;
        r = sqrt(g*g + f*f - c);
        printf("%.2f\n", 2*acos(-1)*r);
    }
    return 0;
}
