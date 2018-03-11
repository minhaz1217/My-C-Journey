# include <iostream>
# include <cstdio>
#include<bits/stdc++.h>
using namespace std;


double torad(double a ){
    return ( (180.0/acos(-1.0)) * a );
}
double dist(double x1,double y1, double x2, double y2){
    double a = fabs(x1-x2);
    double b = fabs(y1-y2);

    return (sqrt( a*a + b*b));
}



int main(){

    double x,y,theta,r = 5.00;
    theta = 110.4258;
    y = cos(torad(theta)) * r;
    x = sin(torad(theta)) * r;
    cout << x << " : " << y << endl;
    cout << dist(-1.16575,4.8622, 3,4) << endl;
    return 0;
}
