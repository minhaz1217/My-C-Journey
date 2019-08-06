/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10522
Date : 07 / August / 2019
Comment: took help. couldn't derive the equation by myself, or find the equation. 3 hours gone.
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
    double n,x,y,z,area;
    cin >> n;
    while(cin >> x >> y >> z){
        x = 1.0/x;
        y = 1.0/y;
        z = 1.0/z;
        area = 1.0 / sqrt( (x+y+z)*(-x+y+z)*(x-y+z) * (x+y-z));
        if(area == 0 || isnan(area)){
            cout << "These are invalid inputs!" << endl;
            n--;
        }else{
            printf("%.3f\n", area);
        }
        if(n==0){
            break;
        }
    }
    return 0;
}
