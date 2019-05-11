/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 17 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct Point
{
public:
	int x;
	int y;
    Point(int xx, int yy){
        x = xx;
        y = yy;
    }
};
double dist(Point a, Point b){
    //return sqrt( (double)(b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
    return ( abs(a.x - b.x) + abs(a.y-b.y) );
}

char dir[] = {'U', 'D', 'L', 'R'};
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int main(){

    int x,y,n,l;
    string str;
    map<char, int> mp;
    char c,choose;
    double currDist;
    cin >> x >> y;
    Point s(x,y);
    cin >> x >> y;
    Point d(x,y);
    cin >> n;
    cin >> str;
    mp['U'] = 0;
    mp['D'] = 1;
    mp['L'] = 2;
    mp['R'] = 3;
    Point currP = s, newP=s,currMax=s;
    l =0;
    msg2("START", currP.x, currP.y)
    while(currDist != 0){
        if(l == n){
            l = 0;
        }
        c = str[l];
        currDist = dist(currP, d);
        currMax = currP;
        //msg(currDist, choose);

        for(int i=0;i<4;i++){
            if(dir[i] == c){
                newP = Point(currP.x + dx[i] + dx[i], currP.y + dy[i] + dy[i]);
            }else{
                newP = Point(currP.x + dx[i] - dx[ mp[c] ], currP.y + dy[i] - dy[ mp[c] ] );
            }
            if( dist(d, newP) <= currDist ){
                currDist = dist(d, newP);
                currMax = newP;
                choose = dir[i];
            }
        }
        currP = currMax;
        msg(currP.x, currP.y)
        l++;
    }
    cc(dist(currP, d))

    return 0;
}
