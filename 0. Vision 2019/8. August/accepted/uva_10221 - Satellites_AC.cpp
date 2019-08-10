/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10221
Date : 10 / August / 2019
Comment: easy problem if you have the equations.
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
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}

int main(){
    double s,a,arcDistance, chordDistance;
    string str;
    while(cin >> s >> a >> str){
        if(str == "min"){
            a = a* (1.0/60.0);
        }else{
            if(a>360){
                a = a -360.0;
            }
        }
        s = 6440.0 + s;
        arcDistance = min(2.0 * PI * s * a / 360.0, 2.0 * PI * s * (360.0-a) / 360.0);
        chordDistance = 2.0 * s* sin( DEG_to_RAD(a/2.0) );

        printf("%.6f %.6f\n", fabs(arcDistance), fabs(chordDistance));
        //cout << arcDistance << " " << chordDistance << endl;
    }
    return 0;
}
