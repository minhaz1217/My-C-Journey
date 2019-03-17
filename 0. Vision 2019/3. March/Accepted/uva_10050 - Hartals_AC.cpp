/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10050
Date : 17 / March / 2019
Comment: Very easy problem, basic use of vector or array.
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


int main(){
    long long int tc;
    cin >> tc;
    while(tc--){
        long long int n,p,a,fri,counter,sat;
        cin >> n >> p;
        vector<int>vec(n+2,0);
        for(int i=0;i<p;i++){
            cin >> a;
            for(int j=a; j<=n;j += a){
                vec[j] = 1;
            }
        }
        fri = 6;
        sat = 7;
        counter = 0;
        for(int i=1;i<=n;i++){
            if(i == fri){
                fri += 7;
                continue;
            }
            if(i == sat){
                sat += 7;
                continue;
            }
            if(vec[i] == 1){
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
