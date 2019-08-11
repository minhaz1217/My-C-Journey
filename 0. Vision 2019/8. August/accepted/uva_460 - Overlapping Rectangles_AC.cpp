/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-460
Date : 11 / August / 2019
Comment: tedious problem. took 3 hours, applied 3 approaches.
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

struct Rect{
    double l,r,t,b;
    Rect(){}
    Rect(double _l, double _r, double _t, double _b):l(_l),r(_r),t(_t),b(_b){}
};
bool isInside(double al, double ar, double bl,double br){
    // checks if a is inside linesegment b
    if(al >= bl && ar <= br){
        return true;
    }
    return false;
}


Rect getColidingRect(Rect a, Rect b){
    vector<double> x,y;
    x.push_back(a.l);
    x.push_back(a.r);
    x.push_back(b.l);
    x.push_back(b.r);

    y.push_back(a.b);
    y.push_back(a.t);
    y.push_back(b.b);
    y.push_back(b.t);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    Rect r(-1,-1,-1,-1);
    for(int i=1;i<x.size();i++){

        if( isInside(x[i-1], x[i], a.l, a.r) && isInside(x[i-1], x[i], b.l, b.r) ){
            if(r.l == -1){
                r.l = x[i-1];
                r.r = x[i];
            }else{
                r.r = x[i];
            }
        }
    }
    for(int i=1;i<y.size();i++){
        if( isInside(y[i-1], y[i], a.b, a.t) && isInside(y[i-1], y[i], b.b, b.t) ){
            if(r.b == -1){
                r.b = y[i-1];
                r.t = y[i];
            }else{
                r.t = y[i];
            }
        }
    }

    return r;
}
int main(){
    double tc, l,b,r,t,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> l >> b >> r >> t;
        Rect r1(l,r,t,b);
        cin >> l >> b >> r >> t;
        Rect r2(l,r,t,b);
        Rect rr = getColidingRect(r1,r2);
        if(caseCounter > 1){
            cout << endl;
        }

        if(rr.l == rr.r  || rr.b == rr.t){ // then it is a line, not a rectangle
            cout << "No Overlap" << endl;
        }else{
            cout << rr.l << " " << rr.b << " " << rr.r << " " << rr.t << endl;
        }
        caseCounter++;
    }
    return 0;
}
