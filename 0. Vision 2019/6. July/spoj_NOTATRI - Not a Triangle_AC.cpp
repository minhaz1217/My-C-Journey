/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/308147#problem/C
Date : 01 / July / 2019
Comment: normal binary search.
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
    long long int n,sum,a,pos;
    while(1){
        vector<long long int>vec;
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        sum = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pos = upper_bound(vec.begin(),vec.end(), vec[i]+vec[j])-vec.begin();
                //msg(vec[i]+vec[j], pos)
                sum += n-pos;
            }
        }
        cout << sum << endl;

    }
    return 0;
}
