/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11909
Date : 08 / August / 2019
Comment: if the normal prism is more than half of the box then the equation changes. took more than 5 hours. even with hint.
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

int main(){
    double hp, l,w,h,t,total, prism1, prism2,ans;
    while(cin >> l >> w >> h >>t ){
        total = l*h*w;
        prism1 = .5 * l * l *w * tan(DEG_to_RAD(t));
        prism2 = .5 * h * h * w*tan( DEG_to_RAD(90.0-t));
        ans = total - prism1;

        if(prism1> total/2.0){
            ans = prism2;
        }

        printf("%.3f mL\n", ans);
        //  msg(total-prism1 , prism2)
    }
    return 0;
}
