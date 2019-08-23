/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11834
Date : 12 / August / 2019
Comment: easy problem?
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
double RAD_to_DEG(double rad){
    return rad*180.0 / acos(-1);
}
int main(){
    double w,l,p,r1,r2,a,b,th,remainingSpace,w2,l2,p2,p3,small;
    while(1){
        cin >> w >> l >> r1 >>r2;
        if(!w && !l && !r1 && !r2){
            break;
        }
        a = max(w,l);
        b = min(w,l);
        w = a;
        l = b;
        a = max(r1,r2);
        b = min(r1,r2);
        r1 = a;
        r2 = b;
        p = (((sqrt(8.0*r1*r1) - (2.0*r1)) /2.0) + 2.0*r1)*sin( DEG_to_RAD(45) ) ;
        //msg(r1,p)
        w2 = w - p;
        l2 = l - p;
//        msg(w2,l2)
//        msg(p,r2)
        p2 = sqrt( w2*w2 + l2*l2 );
        small = (sqrt(8.0*r1*r1) - 2.0 * r1 )/2.0;
        p3 = small + (2.0 * r1 )+ (2.0*r2);
//        msg(small, p3)
        th = atan( (w/l) );
        a = p3 *cos( (th));
//
        msg2(p3,a,small)
        msg(a,RAD_to_DEG(th))
        if(  w>=r1*2.0 && l >= r1*2.0 && ( ( w>=a && l >=a ) || (w>= (r1+r2)*2.0 && l>= max(r1,r2)*2.0) ) ){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }


    }

    return 0;
}
