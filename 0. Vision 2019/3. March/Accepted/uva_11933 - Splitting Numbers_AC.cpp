/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11933
Date : 18 / March / 2019
Comment: Easy Bit manipulation.
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
    long long int n;
    while(1){
        long long int a,counter;
        cin >> n;
        if(n == 0){
            break;
        }
        bitset<33> b(n), b1,b2;
        counter = 1;
        for(int i=0;i<b.size();i++){
            if(b[i] == 1){
                counter++;
            }
            if(counter%2 == 0 && b[i] == 1){
                b1[i] = 1;
            }else if(b[i] == 1 && counter%2 == 1){
                b2[i] = 1;
            }
        }
        cout << b1.to_ulong() << " " << b2.to_ulong() << endl;
    }

    return 0;
}
