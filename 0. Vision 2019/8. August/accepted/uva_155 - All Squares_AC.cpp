/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-155
Date : 11 / August / 2019
Comment: bullshi.t instructions.
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

struct rect{
    double l,r,t,b;
    rect(){}
    rect(double _l, double _r, double _t, double _b):l(_l),r(_r),t(_t),b(_b){}
};
vector<rect>rects;
set<int>st;
void makeRect(rect r, double k){
    if(k == 0){
        return;
    }
    //cc(k)
    double side;
    side = (2.0*k )/2.0;
    rect a( r.l-side, r.l+side, r.b-side, r.b+side ),b( r.r-side, r.r+side, r.b-side, r.b+side ),c(r.r-side, r.r+side, r.t-side, r.t+side),d(r.l-side, r.l+side, r.t-side, r.t+side);
    makeRect(a, (int)k/2);
    makeRect(b, (int)k/2);
    makeRect(c, (int)k/2);
    makeRect(d, (int)k/2);
    rects.push_back(a);
    rects.push_back(b);
    rects.push_back(c);
    rects.push_back(d);
}
void show(rect r){
    msg3(r.l,r.r,r.t,r.b)
}
int main(){

    double k,x,y,side;
    int counter;
    while(1){
        cin >> k  >> x >> y;
        if(!k && !x && !y){
            break;
        }
        rects.clear();
        side = (2.0*k )/2.0;
        rect r1;
        r1.l = 1024.0-side;
        r1.r = 1024.0+side;
        r1.t = 1024.0-side;
        r1.b = 1024.0+side;
        rects.push_back(r1);
        makeRect(r1, (int)k/2);
        //show(r1);
        counter = 0;
        rect r;
        for(int i=0;i<rects.size();i++){
            r = rects[i];
            //show(r);
            if( x>= r.l && x <= r.r && y>=r.t && y<=r.b){
                //msg3(r.l,r.r,r.t,r.b)
                counter++;
            }
        }
        printf("%3d\n", (int)counter);
        //cout << counter << endl;
    }
    return 0;
}
