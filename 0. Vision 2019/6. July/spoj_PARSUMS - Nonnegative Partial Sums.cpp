/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 22 / June / 2019
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


int main(){
    long long int n,counter,sum,a,sz;
    while(1){
        cin >> n;
        sum = 0;
        counter = 0;
        vector<long long int>vec,vec2;
        if(n == 0){
            break;
        }

        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
        }
        sz = vec.size();
        for(int i=0;i<sz;i++){
            vec.push_back(vec[i]);
        }
        sum = 0;
        vec2.push_back(0);
        for(int i=0;i<vec.size();i++){
            sum += vec[i];
            vec2.push_back(sum);
        }
        for(int i=0;i<vec2.size();i++){
            cout << " " << vec2[i];
        }
        cout << endl;

        for(int i=0;i<n;i++){
            //msg(i,i+i+1)
            //msg(i, sum)
            sum = vec2[i+i+1] - vec2[i];
            if(sum>=0){
                counter++;
            }
            //cout << sum << endl;
        }
        cout << counter << endl;


    }

    return 0;
}
