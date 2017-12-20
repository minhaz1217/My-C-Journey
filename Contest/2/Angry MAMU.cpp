#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    float x1,y1,x2,y2,cx,cy,r;
    float m1,m2,angle,len,len1,len2;

    cin >> x1 >> y1 >> x2 >> y2 >> cx >> cy >> r;
    m1 = abs(cy-y1) / abs(cx-x1);
    m2 = abs(cy-y2) / abs(cx-x2);
    angle = abs((m1-m2)/ (1+ m1*m2));
    angle = atan(angle);
    len = angle * r;
    len1 = sqrt(abs(cx-x1)* abs(cx-x1) + abs(cy-y1)*abs(cy-y1)) - r;
    len2 = sqrt(abs(cx-x2)* abs(cx-x2) + abs(cy-y2)*abs(cy-y2)) - r;
    check(m1)
    check(m2)
    check(angle)
    check(len)
    check(len1)
    check(len2)
    cout << len1 + len2 + len << endl;


	return 0;
}
