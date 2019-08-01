/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10832
Date : 30 / July / 2019
Comment: my 200'th UVA solve. very easy problem. online advising day at university, my last advising.
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
    double x, y,z;
    Point(){
        x = y =z = 0.0;
    }
    Point(double _x, double _y, double _z):x(_x), y(_y), z(_z){}
    bool operator == (Point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)&& (fabs(z - other.z) < EPS));
    }
    bool operator < (Point other) const {
        if (fabs(x - other.x) > EPS)
                return x < other.x;
        return y < other.y;
    }
};
double dist(Point a, Point b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z) );
}
int main(){
    int caseCounter = 1;
    double f,b,r,x,y,z,n,minIndex;
    double sum, minDist,currDist,distance,totalDistance, timeTaken, fuelLeft, trav;
    while(1){
        cin >> f >> b >> r >> n;
        if(!f && !b && !r && !n){
            break;
        }
        vector<double> visited(n+1,0);
        vector<Point>vec;
        Point curr(0,0,1),minPoint;
        for(int i=0;i<n;i++){
            cin >> x >> y >> z;
            Point p(x,y,z);
            vec.push_back(p);
        }
        sum = 0;
        while(n--){
            minDist = INT_MAX;
            minIndex= 0;
            for(int j=0;j<vec.size();j++){
                distance = dist(curr, vec[j]);

                if(distance < minDist && !visited[j]){
                    minPoint = vec[j];
                    minDist = distance ;
                    minIndex = j;
                }
            }
            //msg("SELECTED", minIndex)
            visited[minIndex]=1;
            sum += minDist;
            curr = minPoint;
        }
        totalDistance = (f/b)*r;
        //msg2("SUM", sum, totalDistance)
        if(sum <= totalDistance){
            timeTaken = sum / r;
            fuelLeft = f - (b*timeTaken);
            printf("Mission %d: SUCCESS!! Time: %.2f  Traveled: %.2f  Fuel Left: %.2f",caseCounter, timeTaken, sum, fuelLeft);
            //msg2(totalDistance, timeTaken, fuelLeft)
        }else{
            trav = sum - totalDistance;
            printf("Mission %d: FAILURE!! Traveled: %.2f  From Home: %.2f",caseCounter,  totalDistance, trav);
        }
        caseCounter++;
        cout << endl;

    }

    return 0;
}
