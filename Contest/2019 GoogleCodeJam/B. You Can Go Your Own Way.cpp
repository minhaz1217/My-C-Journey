/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 07 / April / 2019
Comment:
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
struct pos{
    int x,y,len;
    bitset<1000040>b;
};
int r,c;
#define MX 1504
int matE[MX][MX];
int matS[MX][MX];
int main(){
    long long int tc,n,r,c,dr,dc,x,y, caseCounter =1;
    pos pp;
    string str,temp;
    cin >> tc;
    while(tc--){
        map<pair<int,int>, int> mp;
        cin >> n >> str;
        r = 0;
        c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matE[i][j] = 0;
                matS[i][j] = 0;
            }
        }
        for(int i=0;i<str.size();i++){
            if(str[i] == 'E'){
                matE[r][c] = 1;
                c++;
            }else if(str[i] == 'S'){
                matS[r][c] = 1;
                r++;
            }
        }
        dr = r;
        dc = c;
        queue<pos>q;
        //queue<pair<int,pair<int,string> > >q;
        pos p;
        p.x = 0;
        p.y = 0;
        p.len = 0;
        q.push(p);
        while(!q.empty()){
            p = q.front();
            x = p.x;
            y = p.y;
            //msg2(x,y,pos)
            q.pop();
            if(p.len> str.size()){
                continue;
            }
            if(p.x== dr && p.y == dc && p.len == str.size()){
                //msg("HI", pos)
                break;
            }
            if( ( matE[x][y] != 1 ) && p.x+1 < n){
                pp = p;
                pp.x++;
                pp.len++;
                q.push(pp);
                matE[x][y] = 1;
            }
            if(  ( matS[x][y] != 1) && p.y+1 < n){
                pp = p;
                pp.y++;
                pp.b[pp.len] = 1;
                pp.len++;
                q.push(pp);
                matS[x][y] = 1;
            }
        }
        temp = "";
        for(int i=0;i<p.len;i++){
            if(p.b[i] == 0){
                temp += "E";
            }else{
                temp += "S";
            }
        }
        cout << "Case #"<<caseCounter++ <<": " << temp << endl;
    }


    return 0;
}
