/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-681
Date : 01 / September / 2019
Comment: what happens if single point, or co linear points. my convex hull was giving wrong answer.
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
    Point(){
        x = y = 0.0;
    }
    Point(double _x, double _y):x(_x), y(_y) {}
    bool operator == (Point other) const{
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (Point other) const{
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
};
double dist(Point p1, Point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool cmp(Point a,Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convexHullSort(vector<Point>& a) {
    // gives right answer for collinear points.
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
void show(Point p){
    cout << "(" << p.x << "," << p.y <<")" << endl;
}
int main(){
    long long int tc,n;
    double x,y;
    cin >> tc;
    cout << tc << endl;
    while(tc--){
        vector<Point>poly,ans,temp;
        set<Point>st;
        cin >> n;
        poly = vector<Point>();
        ans = vector<Point>();
        for(int i=0;i<n;i++){
            cin >> x >> y;
            st.insert(Point(x,y));
            //poly.push_back(Point(x,y));
        }
        poly = (vector<Point>(st.begin(),st.end()));
        convexHullSort(poly);

        poly.push_back(poly[0]);
        if(poly.size()<3){
            poly.push_back(poly[0]);
        }
        reverse(poly.begin(),poly.end());
        poly.pop_back();
        Point curr = poly[0];
        int mn = 0;
        for(int i=0;i<poly.size();i++){
            if(poly[i].y < curr.y){
                curr = poly[i];
                mn = i;
            }else if(poly[i].y == curr.y){
                if(poly[i].x < curr.x){
                    curr = poly[i];
                    mn = i;
                }
            }
        }

        ans.insert(ans.end(), poly.begin()+mn, poly.end());
        ans.insert(ans.end(), poly.begin(), poly.begin()+mn);
        ans.push_back(ans[0]);

        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++){
            cout << ans[i].x << " "<< ans[i].y << endl;
        }

        if(tc != 0){
            cin >> x;
            cout << x << endl;
        }

    }
    return 0;
}
