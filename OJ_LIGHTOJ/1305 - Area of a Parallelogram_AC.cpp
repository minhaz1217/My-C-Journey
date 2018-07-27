#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

struct point{
    int x,y;
};

double calculate(point b, point a){
    return ( sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) );
}


int main(){
    int tc,caseCounter = 1;
    scanf("%d", &tc);
    while(tc--){
        point a,b,c,d;
        scanf("%d%d%d%d%d%d",&a.x, &a.y, &b.x , &b.y, &c.x, &c.y );
        d.x = c.x - (b.x-a.x);
        d.y = a.y + (c.y - b.y);
        //msg(d.x, d.y)
        double d1,d2;
        d1 = calculate(a,b);
        d2 = c.y-b.y;
        int x1,x2,y1,y2,x3,y3,x4,y4,area;
        x1 = a.x;
        y1 = a.y;
        x2 = b.x;
        y2 = b.y;
        x3 = c.x;
        y3 = c.y;
        x4 = d.x;
        y4 = d.y;
        area = ( (x1 *y2- x2*y1)  + (x2*y3 - x3*y2) + (x3*y4- x4*y3) + (x4*y1-x1*y4) )/2;
        area = abs(area);
        printf("Case %d: %d %d %d\n", caseCounter++, d.x,d.y, area);
        //cc(calculate(a,b))
        //cc(calculate(b,c))
    }

    return 0;
}
