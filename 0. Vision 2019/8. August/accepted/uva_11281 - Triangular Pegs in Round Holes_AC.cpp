/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11281
Date : 07 / August / 2019
Comment: had to take hint fro cpbook because of the obtuse triangle.
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
    double m,n,a,b,c,s,r,degA,degB,degC;
    vector<double>circles;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a;
        circles.push_back(a/2.0);
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;

        degA =  RAD_to_DEG (acos( ( (b*b)+(c*c) - (a*a) ) / (2.0 * b*c) ) );
        degB = RAD_to_DEG ( acos( ( (a*a)+(c*c) - (b*b) ) / (2.0 * a*c)) );
        degC = 180.0 - (degA + degB);
        //msg2(degA,degB, degC)
        s = (a+b+c)/2.0;
        r = (a*b*c) / (4.0 * sqrt(s*(s-a)*(s-b)*(s-c)) );
        vector<long long int> vec;
        if(degA > 90.0 || degB > 90.0 || degC >90.0){
            r = max(a,max(b,c) )/2.0;
        }
        for(int j=0;j<circles.size();j++){
            double t = circles[j];
            if(r <= circles[j]){
                vec.push_back(j+1);
            }
        }

        if(vec.size()>0){
            cout << "Peg "<< char('A' + i)<< " will fit into hole(s):";
            for(int j=0;j<vec.size();j++){
                cout << " " << vec[j];
            }
            cout << endl;
        }else{
            cout << "Peg "<< char('A' + i)<< " will not fit into any holes" << endl;
        }

    }
    return 0;
}
