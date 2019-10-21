/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://toph.co/arena?contest=ngpc-2019-preliminary-r#!/p/weird-cake
Date : 21 / October / 2019
Comment:
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

int main(){
    double h,h1,h2, r,cv,ch,vol1,vol2,vol3,fullVol,vol22,hh,r1, r2;
    while(cin>> h >> h1 >> h2){
        ch = h-h1;
        r = h/2.0;
        vol1 = PI * ch * ch*( r - (ch/3.0) );
        hh = h - h1;
        r1 = sqrt( (2.0 * r * hh) - (hh*hh) );
        hh = h - h2;
        r2 = sqrt( (2.0 * r * hh) - (hh*hh) );
        hh = h1 - h2;
        vol22 = (1/6.0) * PI * hh * ( 3.0*r1*r1 + 3.0*r2*r2 + hh*hh );

        ch = h-h2;
        vol2 = PI * ch * ch*( r - (ch/3.0) );
        vol2 = vol2-vol1;
        vol3 = ((4/3.0)*PI*r*r*r) - (vol1 + vol22);
        fullVol = ((4/3.0)*PI*r*r*r);
        //cout << vol22 << endl;
        vector<double>vec;
        vec.push_back(vol1);
        vec.push_back(vol22);
        vec.push_back(vol3);
        sort(vec.begin(),vec.end());
        printf("%.6f %.6f %.6f\n", vec[0],vec[1],vec[2]);
    }
    return 0;
}
