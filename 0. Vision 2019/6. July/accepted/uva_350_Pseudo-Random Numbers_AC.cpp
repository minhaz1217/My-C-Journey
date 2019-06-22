/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-350
Date : 22 / June / 2019
Comment: shafayet's blog told to solve this using floyed's cycle finding, but didn't need that algorithm.
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
    long long int z,i,m,l,counter,caseCounter = 1;

    while(1){
        map<long long int, int> mp;
        cin >> z >> i >> m >> l;
        if(!z && !i && !m &&!l){
            break;
        }
        counter = 0;
        while(1){
            l = ((z*l)+i)%m;
            if(!mp[l]){
                counter++;
                mp[l] = 1;
            }else{
                break;
            }
        }
        cout <<"Case " << caseCounter++ <<": " <<  counter << endl;
    }
    return 0;
}
