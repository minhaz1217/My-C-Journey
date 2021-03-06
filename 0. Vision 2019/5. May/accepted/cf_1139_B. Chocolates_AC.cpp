/*
Minhazul Hayat Khan
minhaz1217.github.io
www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: http://codeforces.com/contest/1139/problem/B
Date : 12 / May / 2019
Comment: easy problem
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
    long long int n,a,prev,sum=0;
    vector<long long int > vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    prev = *(vec.end()-1);
    sum += prev;
    //msg(sum , prev)
    for(int i=vec.size()-2;i>=0;i--){
        if(vec[i]<prev){
            sum += vec[i];
            prev = vec[i];
        }else{
            prev = prev -1;
            if(prev>0){
                sum += prev;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
