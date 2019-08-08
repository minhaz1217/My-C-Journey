/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11579
Date : 08 / August / 2019
Comment: easy problem.
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

double triangleArea( double a, double b, double c ){
    double s = (a+b+c)/2.0;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return area;
}

int main(){
    //cc(triangleArea(85.608,51.381,35.568))
    double tc,n,a,b,c,area,mx;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<double>vec;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        area = 0;
//        for(int i=0;i<vec.size();i++){
//            msg(i,vec[i])
//        }
        int sz = vec.size();
        mx = INT_MIN;
        for(int i=vec.size()-1;i>=2;i--){
            //msg(i,vec[i])
            if(vec[i-1]+vec[i-2]> vec[i]){
                a = vec[i];
                b = vec[i-1];
                c = vec[i-2];
                area = triangleArea(a,b,c);
                mx = max(mx, area);
            }
        }
        area = mx;
        if(area < 1e-7 || isnan(area)){
            area = 0;
        }
        printf("%.2f\n",area);
    }
    return 0;
}
