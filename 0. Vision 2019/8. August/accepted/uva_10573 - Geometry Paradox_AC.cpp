/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10573
Date : 11 / August / 2019
Comment: easy problem if the solution IS what I think it is.
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
    long long int tc;
    string str;
    cin >> tc;
    cin.ignore();
    while(tc--){
        double a,r1,r2,area;
        getline(cin,str);
        stringstream ss(str);
        r1 = INT_MIN;
        r2 = INT_MIN;
        while(ss >> a){
            if(r1 == INT_MIN){
                r1 = a;
            }else{
                r2 = a;
            }
        }
        if(r2 == INT_MIN){
            area = PI * (r1/2.0)*(r1/2.0) - 2.0*(PI * (r1/4.0)*(r1/4.0) );
        }else{
            area = PI *(r1+r2)*(r1+r2) - (PI*r1*r1 + PI*r2*r2);
        }
        printf("%.4f\n", area);

    }
    return 0;
}
