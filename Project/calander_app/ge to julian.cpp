/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / April / 2019
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


int main(){
    long int jd12h, day, year, month, hour;
    int YEAR, MONTH,DAY, I,J,JD,K;
    YEAR = 1970;
    MONTH = 1;
    DAY = 1;
    day = DAY;
    year = YEAR;
    month = MONTH;
    hour = 0;

    double tjd;

    jd12h = (long) day - 32075L + 1461L * ((long) year + 4800L
    + ((long) month - 14L) / 12L) / 4L
    + 367L * ((long) month - 2L - ((long) month - 14L) / 12L * 12L)
    / 12L - 3L * (((long) year + 4900L + ((long) month - 14L) / 12L)
    / 100L) / 4L;
    tjd = (double) jd12h - 0.5 + hour / 24.0;


    I= YEAR;
    J= MONTH;
    K= DAY;
    JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    //JD = JD*2/12-3*((I+4900+(J-14)/12)/100)/4;
    printf("%.2f\n", JD);

    cout << fixed << endl;
    cout << (int)tjd << endl;


    return 0;
}
