/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10357
Date : 30 / July / 2019
Comment: was having problem with double at first, converted everything to int, then got AC
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
    int x, y;
    Point(){
        x = y = 0.0;
    }
    Point(long long int _x, long long int _y):x(_x), y(_y) {}
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const {
        if (fabs(x - other.x) > EPS)
                return x < other.x;
        return y < other.y;
    }
};

double pointDistance(Point p1, Point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

long long int a,b,c,d,e,f,g;

long long int getX(long long int t){
    return d*t + e;
}
long long int getY(long long int t){
    return f*t + g;
}
long long int getZ(long long int t){

    return a*t*t + b *t + c;
}

int main(){
    long long int x,y,z,v,flag,t;
    char str[100];
    int player, ball,tc;
    vector<pair<double, Point> > players, vec;
    scanf("%[^0-9]c", str);
    cin >> tc;
    while(tc--){
        cin >> x >> y >> v;
        players.push_back(make_pair(v, Point(x,y)));
    }
    scanf("%[^0-9]c", str);
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c >> d >> e >> f >> g;
        for(int i=1;i<=10;i++){
            x = getX(i);
            y = getY(i);
            z = getZ(i);
            if(z<=0){
                vec.push_back(make_pair(i, Point(x,y)));
                break;
            }
        }
    }
    for(int i=0;i<vec.size();i++){
        Point p = vec[i].second;
        t = vec[i].first;
        if( (p.x) < 0 || (p.y) < 0   ){
            printf("Ball %d was foul at (%d,%d)\n", i+1, p.x,p.y);
        }else{
            flag = 0;
            for(int j=0; j<players.size(); j++){
                Point p2 = players[j].second;
                v = players[j].first;
                double dist = pointDistance(p,p2);
                if(  (v*t) >= dist ){
                    //msg(v*t, dist);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                printf("Ball %d was safe at (%d,%d)\n", i+1, p.x,p.y);
            }else{
                printf("Ball %d was caught at (%d,%d)\n", i+1, p.x,p.y);
            }
        }
    }


    return 0;
}
