# include <iostream>
# include <cstdio>
#include<bits/stdc++.h>
using namespace std;
double totheta(double a ){
    return ( (180.0/acos(-1.0)) * a );
}
double pointToDegree(double a, double b){
    return (double)atan((double)b/(double)a);
}
double torad(double a ){
    return ( (180.0/acos(-1.0)) * a );
}
double dist(double x1,double y1, double x2, double y2){
    double a = fabs(x1-x2);
    double b = fabs(y1-y2);

    return (sqrt( a*a + b*b));
}
int main(){
    double bx,by,ax,w,t,th1,mov,r,x2,y2, th2, res,res2;
    cin >> bx >> by >> ax >> w >> t;

    double PI = (double)acos(-1.00);
    printf("%.8lf\n", PI);
    r = (double)sqrt( bx*bx+by*by );
    th1 = pointToDegree(bx, by);
    printf("%.8lf\n", th1);

    mov = totheta(w*t);
    printf("%.8lf\n", mov);

    res = (2.00*PI*r) / 360.00 * mov;
    printf("%.8lf\n", res);

    res2 = ax - res;

    printf("%.8lf\n", ax);
    printf("%.8lf\n", res2);

    /*
    th2 = th1+ mov;
    y2 = cos(torad(th2)) * r;
    x2 = sin(torad(th2)) * r;
    cout << mov << endl;
    res = ax - dist(bx,by, x2, y2);
    cout << res << endl;
    */






    return 0;
}
