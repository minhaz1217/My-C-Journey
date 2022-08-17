/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/bug-in-a-cineplex
Complexity:
Date : 16 / Aug / 2022

Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


double calculate(pair<double, double> p1, pair<double, double> p2){
    return ((( p2.second - p1.second ) / (p2.first - p1.first)) * (-1 * p1.first) ) + p1.second;
}

int main(){
    _INIT;
    int tc;
    double x,y;
    cin >> tc;
    while(tc--){
        int n;
        vector<pair<double,double> > vec;
        double currentY;
        cin >> n;
        while(n--){
            cin >> x >> y;
            vec.push_back(make_pair(x,y));
        }
        if(vec.size() == 1){
            cout << vec[0].second << endl;
        }else{
            double currentY = calculate( vec[0], vec[1] );
            for(int i=1;i<vec.size();i++){
                currentY = max(currentY , calculate( vec[i], make_pair(0,currentY) ));
            }
            cout << (double)currentY << endl;
        }
    }
    return 0;
}
