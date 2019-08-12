/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2686
Date : 12 / August / 2019
Comment: super easy problem.
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
Rect commonRectSmall(Rect a, Rect b){
    Rect r;
    r.l = max(a.l,b.l);
    r.r = min(a.r,b.r);
    r.b = max(a.b,b.b);
    r.t = min(a.t,b.t);
    if(r.l > r.r || r.b > r.t){
        r = Rect(-1,-1,-1,-1);
    }
    return r;
}
int main(){
    double tc,l,r,b,t,fullRectAre, g1Area, g2Area, strongArea, weakArea, unsecuredArea,fullRectArea;
    int caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> l >> b >> r >> t;
        Rect r1(l,r,t,b);
        cin >> l >> b >> r >> t;
        Rect r2(l,r,t,b);
        Rect r3 = commonRectSmall(r1,r2);


        fullRectArea = 10000;
        g1Area = (r1.r-r1.l)*(r1.t-r1.b);
        g2Area = (r2.r-r2.l)*(r2.t-r2.b);
        strongArea = (r3.r-r3.l)*(r3.t-r3.b);
        weakArea = g1Area + g2Area - 2.0*(strongArea);
        unsecuredArea = fullRectArea - weakArea - strongArea;
        printf("Night %d: %.0f %.0f %.0f\n", caseCounter++, strongArea, weakArea, unsecuredArea);


    }
    return 0;
}
