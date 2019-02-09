/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11219
Date : 09 / February / 2019
Comment: Individual Contest 9, Very easy problem.
*/
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a<< " : " << b << endl;
#define msg2(a,b,c) cout << a<< " : " << b << " : " << c<< endl;
#define msg3(a,b,c,d) cout << a<< " : " << b << " : " << c << " : " << d << endl;
int calculateYear(int d1, int m1, int y1, int d2, int m2, int y2){

    int year = y1 - y2;
    if(m2 > m1){
        year--;
    }else if(m1 == m2){
        if(d2 > d1){
            year--;
        }
    }
    return year;
}
int main(){
    int tc,caseCounter =1 ,year, d1,m1,y1, d2,m2,y2;
    char c;
    cin >> tc;
    while(tc--){
        cin >> d1 >> c >> m1 >> c >> y1;
        cin >> d2 >> c >> m2 >> c >> y2;
        year = calculateYear(d1,m1,y1,d2,m2,y2);
        cout << "Case #" << caseCounter++ << ": ";
        if(year < 0){
            cout << "Invalid birth date" << endl;
        }else if(year > 130){
            cout << "Check birth date" << endl;
        }else{
            cout <<year << endl;
        }
    }
    return 0;
}
