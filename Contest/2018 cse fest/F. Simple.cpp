#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;
struct point{
    double x , y;
    point(double aa, double bb){
    x = aa;
    y = bb;
    }
};
double calc(point a, point b){
    return sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)* (b.y - a.y) );
}


int main(){
    int tc;
    double a,b,c,d,t,dis;
    cin >> tc;

    while(tc--){
        cin >> a >> b >> c >> d >> t >>dis;
        point A(a,b), B(c,d);
        for(i=0;i<=dis;i++){
            for(j=0;j<=dis;j++){
                msg(i, arctan)
            }
        }
    }



    return 0;
}
