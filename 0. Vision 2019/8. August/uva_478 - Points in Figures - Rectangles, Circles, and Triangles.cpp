/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-478
Date : 29 / August / 2019
Comment: polygon problem that doesn't need polygon. on the line isn't inside.
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
double dist(double x1, double y1, double x2, double y2){
    return (double)hypot(x2-x1, y2-y1);
}

bool checkRect(double x, double y, vector<double>vec){
    double t = vec[1];
    double l = vec[0];
    double b = vec[3];
    double r = vec[2];
    if( x > l && x< r && y>b && y<t){
        return 1;
    }
    return 0;
}

bool checkCircle(double x, double y, vector<double>vec){
    double a = dist(x,y, vec[0],vec[1]);
    double b = vec[2];
    //msg(a,b);
    if(a<b){
        return 1;
    }
    return 0;
}
double triangleArea(double ax, double ay, double bx, double by, double cx, double cy){
    double ab = dist(ax,ay,bx,by);
    double bc = dist(cx,cy,bx,by);
    double ca = dist(ax,ay,cx,cy);
    double s = (ab+bc+ca)/2.0;
    return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

bool checkTriangle(double x, double y, vector<double>vec){
    double a =triangleArea( vec[0],vec[1],vec[2],vec[3],vec[4],vec[5]);
    double b = ( triangleArea( x,y,vec[2],vec[3],vec[4],vec[5] )+triangleArea( vec[0],vec[1],x,y,vec[4],vec[5] ) + triangleArea( vec[0],vec[1],vec[2],vec[3],x,y ));
    //msg(a,b);

    if( fabs(dist(vec[0],vec[1],vec[2],vec[3]) - (dist(x,y,vec[2],vec[3]) + dist(vec[0],vec[1],x,y))) <= EPS ||
        fabs(dist(vec[4],vec[5],vec[2],vec[3]) - (dist(x,y,vec[4],vec[5]) + dist(vec[2],vec[3],x,y))) <= EPS ||
        fabs(dist(vec[0],vec[1],vec[4],vec[5]) - (dist(x,y,vec[4],vec[5]) + dist(vec[0],vec[1],x,y))) <= EPS   ){
            return 0;
    }
    if( fabs(  a - b  ) <= EPS  ){
        return 1;
    }
    return 0;
}

int main(){
    int mainFlag ,caseCounter = 0,flag;
    char c;
    double a,x,y;
    vector<pair<char, vector<double> > > fig;
    while(1){
        cin >> c;
        if(c == '*'){
            break;
        }
        vector<double>vec;
        if(c == 'r'){
            for(int i=0;i<4;i++){
                cin >> a;
                vec.push_back(a);
            }
        }else if(c == 'c'){
            for(int i=0;i<3;i++){
                cin >> a;
                vec.push_back(a);
            }
        }else if(c == 't'){
            for(int i=0;i<6;i++){
                cin >> a;
                vec.push_back(a);
            }
        }

        fig.push_back(make_pair(c, vec));
    }

    while(cin >> x >> y){
        caseCounter++;
        if(x == 9999.9 && y == 9999.9){
            break;
        }
        mainFlag = 0;
        for(int i=0;i<fig.size();i++){
            c = fig[i].first;
            flag = 0;
            if(c == 'c'){
                flag = checkCircle(x,y, fig[i].second);
            }else if(c == 'r'){
                flag = checkRect(x,y, fig[i].second);
            }else if(c == 't'){
                flag = checkTriangle(x,y, fig[i].second);
            }
            if(flag == 1){
                mainFlag = 1;
                printf("Point %d is contained in figure %d\n", caseCounter, i+1);
            }
        }
        if(mainFlag == 0){
            printf("Point %d is not contained in any figure\n", caseCounter);
        }
    }
    return 0;
}
