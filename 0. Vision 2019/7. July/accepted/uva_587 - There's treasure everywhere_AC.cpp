/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-587
Date : 25 / July / 2019
Comment: building and testing the template. Had MASSIVE problem with -0
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

#define EPS 1e-9
struct Point{
    double x, y;
    Point()
    {
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
};
double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
Point rotate(double x,double y, double theta) {
    Point p(x,y);
    double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return Point(p.x * cos(rad) - p.y * sin(rad),
    p.x * sin(rad) + p.y * cos(rad));
}
double dist(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
int main(){

    Point p;
    p = rotate(10.0,0.0,135.0);
    //msg(p.x,p.y)
    string str="",temp = "";
    string c;
    long long int sz,a,caseCounter = 1;
    double x,y,px,py;
    while(getline(cin, str)){

        if(str == "END"){
            break;
        }
        x = 0;
        y = 0;
        sz = str.size();
        temp = "";
        for(int i=0;i<sz;i++){
            if(str[i] == ',' || str[i] == '.'){
                stringstream ss(temp);
                ss >> a >> c;
                //msg2(a,c,temp)
                //msg2("HI", x,y)
                if(c == "E"){
                    x +=a;
                }else if(c == "W"){
                    x -= a;
                }else if(c == "N"){
                    y += a;
                }
                else if(c == "S"){
                    y -= a;
                }else if(c == "NE"){
                    px = x;
                    py = y;
                    p = rotate(0+a,0,45);
                    x = p.x+ px;
                    y = p.y+ py;
                }else if(c == "NW"){
                    px = x;
                    py = y;
                    p = rotate(0+a,0,45+90);
                    x = p.x+ px;
                    y = p.y+ py;
                }else if(c == "SW"){
                    px = x;
                    py = y;
                    p = rotate(0+a,0,45+2*90);
                    x = p.x+ px;
                    y = p.y+ py;
                }else if(c == "SE"){
                    px = x;
                    py = y;
                    p = rotate(0+a,0,45+3*90);
                    x = p.x+ px;
                    y = p.y+ py;
                }
                temp = "";
            }else{
                temp.push_back(str[i]);
            }
        }
        if( fabs(x -0) <= EPS){
            x = 0;
        }
        if(fabs(y -0) <= EPS){
            y = 0;
        }
        p= Point(x,y);
        printf("Map #%lld\n", caseCounter++);
        printf("The treasure is located at (%.3f,%.3f).\n", p.x, p.y);
        printf("The distance to the treasure is %.3f.\n", dist(Point(0,0), p));
        cout << endl;
        //msg(x,y);
    }

    return 0;
}
