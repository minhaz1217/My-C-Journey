/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-152
Date : 25 / July / 2019
Comment: unclear question
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
struct point{
    double x,y,z;
};
double dist(pair<double, pair<double, double> > a, pair<double, pair<double, double> > b){
    ///msg2(a.x,a.y,a.z)
    return (double)( sqrt( (a.first-b.first)*(a.first-b.first) + (a.second.first-b.second.first)*(a.second.first-b.second.first)+(a.second.second-b.second.second)*(a.second.second-b.second.second) ));
}
int main(){
    vector<pair<double, pair<double, double> > >vec;
    vector<long long int> pts(11,0);
    pair<double, pair<double, double> > prev;
    double x,y,z;
    long long int mn;
    while(1){
        cin >> x >> y >> z;
        if(!x && !y && !z){
            break;
        }
        vec.push_back(make_pair(x, make_pair(y,z)));
    }
    for(int i=0;i<vec.size();i++){
        mn = INT_MAX;
        for(int j=0;j<vec.size();j++){
            if(i!=j){
                long long int temp = dist(vec[i], vec[j]);
                mn = min(temp, mn);
            }
        }
        pts[ (int)min(100ll, mn) ]++;
    }
    for(int i=0;i<=9;i++){
        printf("%4lld", pts[i]);
    }
    cout << endl;

    return 0;
}
