/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10865
Date : 01 / August / 2019
Comment: just basic quadrant calculation.
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
    double tc,x,y,s,o,midX, midY;
    while(cin >> tc){
        if(tc==0){
            break;
        }
        vector<pair<double,double> > vec;
        for(int i=0;i<tc;i++){
            cin >> x >> y;
            vec.push_back(make_pair(x,y));
        }
        midX = vec[tc/2].first;
        midY = vec[tc/2].second;
        s = 0;
        o = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first == midX && vec[i].second == midY){
                continue;
            }
            x = vec[i].first;
            y = vec[i].second;
            if(x > midX && y >midY){
                s++;
            }else if(x < midX && y >midY){
                o++;
            }else if(x > midX && y <midY){
                o++;
            }else if(x<midX && y < midY){
                s++;
            }

            //msg3(x,y, s,o)
        }
        cout << s << " " << o << endl;
    }
    return 0;
}
