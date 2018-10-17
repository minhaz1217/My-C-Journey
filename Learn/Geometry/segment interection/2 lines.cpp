#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define P  complex<long long int>
#define X real()
#define Y imag()
double cross_product(P a, P b){
    return (conj(a)*b).imag();
}

double cross_product(P a, P b , P c){
    return ( (b.X-a.X)*(c.Y-a.Y) - (c.X-a.X)*(b.Y-a.Y) );
}
void display(P a){
    cout << "("<< a.real() << "," << a.imag() << ")"<< endl;
}
double whichSide(P s1, P s2, P p){
    return (cross_product(p-s1, p-s2));
}

int main(){

    P p1(2, 0), p2(2,7), p3(5,0);
    msg3(p1.X, p1.Y, p2.X, p2.Y)

    double cp = cross_product(p1,p2);
    cout << cp << endl;
    if(cp == 0){
        cout << "Co-Linear" << endl;
    }else if(cp >0){
        cc("Anti clock wise")
    }else{
        cc("CLOCK WISE")
    }

    double myCp = cross_product(p1,p2,p3);
    cc(cross_product(p1,p2,p3))
    cc(cross_product(p1,p3))


    //pt is on the left or right of p4,p5
    cc("CHECKING If a point P is on the left or right of a line a, b")
    P p4(5,0), p5(20,0),ptl(10,10), ptr(10,-10);
    cc(cross_product(ptl - p4, ptl-p5))
    cc(cross_product(ptr - p4, ptr-p5))

    cc("Line segment intersection")
    cc("First case: 2 lines are on the same line")
    P la(1,1), lb(10,10), lc(14,14), ld(20,20);
    cout << "Line a, b" << endl;
    display(la);
    display(lb);
    cout << "Line c,d" << endl;
    display(lc);
    display(ld);
    msg("Checking if C is colinear to the line AB", whichSide(la, lb, lc))
    msg("Checking if D is colinear to the line AB", whichSide(la, lb, ld))
    cc("As they are all colinear, now we sort the values and find interection points.")

    cc("Case 2: the lines intersect at one of the points, ie: where one line stops, another begins")
    P ma(1,1), mb(5,5), mc(5,5), md(10,20);
    cout << "Line a, b" << endl;
    display(ma);
    display(mb);
    cout << "Line c,d" << endl;
    display(mc);
    display(md);
    cc("Solution: just check if any points are same or not")

    cc("Case 3: the lines form an X, with crossing")
    cc("Solution: check if the 2 points of CD are on opposite side of AB")

    return 0;
}
