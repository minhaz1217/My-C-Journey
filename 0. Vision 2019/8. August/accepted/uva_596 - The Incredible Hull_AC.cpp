/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-596
Date : 31 / August / 2019
Comment: tedious problem. it has good input output. otherwise there might have been a problem. WA: multiple same point from a single P is not acceptable. but same point can be in different polygon. there is a set of identifier for each test case.
S Sample 1
P 10 8 0 8 8 0 8 5 6 2 3 0 0 0 1 0 2 0 10 0 100
P 5 6 13 2 18 2 13 0 1 0 2
P 6 15 6 15 14 10 14 10 6 0 1 0 2
S MyProblem 1
P 3 -10 0 0 1 1 1
P 3 -10 0 0 1 1 1
P 3 -10 0 0 1 1 1
END


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

struct vec{
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(Point a, Point b){
	// convert 2 Points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}
// note: to accept collinear Points, we have to change the ‘> 0’
// returns true if Point r is on the left side of line pq
bool ccw(Point p, Point q, Point r){
    return cross(toVec(p, q), toVec(p, r)) >= 0;
}
// returns true if Point r is on the same line as the line pq
bool collinear(Point p, Point q, Point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

Point pivot(0, 0);
bool angleCmp(Point a, Point b){
	// angle-sorting function
    if (collinear(pivot, a, b)){
		// special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
	}
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} // compare two angles

vector<Point> convexHull(vector<Point> P){
// the content of P may be reshuffled
	int i, j, n = (int)P.size();
    if (n <= 3){
        if (!(P[0] == P[n-1])){
            P.push_back(P[0]); // safeguard from corner case
		}
        return P;
    } // special case, the CH is P itself
// first, find P0 = Point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++){
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)){
            P0 = i;
		}
	}
    Point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp; // swap P[P0] with P[0]
// second, sort Points by angle w.r.t. pivot P0
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
// to be continued
// continuation from the earlier part
// third, the ccw tests
    vector<Point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n){// note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])){
            S.push_back(P[i++]); // left turn, accept
		}else{
            S.pop_back();
		}
    } // or pop the top of S until we have a left turn
    return S;
}


bool compare(Point a, Point b){
    if(a.x > b.x){
        return 1;
    }else if(a.x < b.x){
        return 0;
    }else{
        if(a.y > b.y){
            return 0;
        }else{
            return 1;
        }
    }
}
vector<Point>gp;
string caseCounter ,currSample;
void returnOutput(){
    if(gp.size()!=0){
        gp = convexHull(gp);
        //msg(gp.size(), "H")
        if(gp.size()!=1){
            gp.pop_back();
        }

        int sz = gp.size();
        int pos;
        pos = 0;
        Point currMx = gp[0];
        for(int i=0;i<gp.size();i++){
            if(gp[i].x > currMx.x){
                pos = i;
                currMx = gp[i];
            }else if(gp[i].x == currMx.x && gp[i].y < currMx.y){
                pos = i;
                currMx = gp[i];
            }
        }
        vector<Point> myvec;
        myvec = gp;
        gp.insert(gp.end(), myvec.begin(),myvec.end());
        //gp = gp+gp;
        currMx = gp[pos+sz-1];
        cout << caseCounter <<" convex hull:" << endl;
        for(int i=pos;i<pos+sz;i++){
            if(gp[i] == currMx){
                break;
            }
            printf(" (%.0f,%.0f)",gp[i].x, gp[i].y);
        }
        printf(" (%.0f,%.0f)",currMx.x, currMx.y);
        cout << endl;
        gp = vector<Point>();
    }
}
int main(){

    long long int x,y,n;
    string c;
    while(1){
        cin >> c;
        if(c == "END"){
            caseCounter = currSample;
            returnOutput();
            break;
        }else if(c == "S"){
            cin.ignore();
            getline(cin,currSample);
            returnOutput();
            caseCounter = currSample;
            continue;
        }
        cin >> n;
        set<Point> st;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            st.insert(Point(x,y));
        }
        gp.insert(gp.end(), st.begin(),st.end());
    }
    return 0;
}
