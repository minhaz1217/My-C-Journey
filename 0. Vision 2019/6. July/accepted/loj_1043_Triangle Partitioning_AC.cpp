/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name: Triangle Partitioning
Problem Link: https://vjudge.net/problem/LightOJ-1043
Date : 22 / May / 2019
Comment: Easy geometric binary search, had to take hint of ad/ab = ae/ac = de/bc from shafayet's blog
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

double area(double a, double b, double c){
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
    double tc,ab,ac,bc,r,ade,ad,ae,de,l,rr,ar;
    int caseCounter = 1;
    cin >> tc;

    while(tc--){
        cin >> ab >> ac >> bc >> rr;
        ade = area(ab,ac,bc)*rr / (rr+1.0);
        l = 0.0;
        r = max(ab , max(ac,bc));
        while(l<r){

            ad = (l+r)/2.0;
            ae = (ac/ab)*ad;
            de = (bc/ab)*ad;
            ar = area(ad, ae, de);
        //msg(ad, ar)
            if(abs(ar- ade) <= .0000000001){
                break;
            }
            if(ar > ade){
                r = ad;
            }else{
                l = ad;
            }
        }
        printf("Case %d: %.8lf\n", caseCounter++, ad);
        //msg("ANSWER", ad)
    }

    return 0;
}
