/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/external/129/12996.pdf
Date : 25 / October / 2019
Comment: easy problem.
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
    long long int tc,n,l,a,sum,caseCounter = 1,flag;
    cin >> tc;
    while(tc--){
        sum = 0;
        flag = 1;
        vector<long long int>vec;
        cin >> n >> l;
        for(int i=0;i<n;i++){
            cin >> a;
            sum += a;
            vec.push_back(a);
        }
        for(int i=0;i<n;i++){
            cin >> a;
            if(a<vec[i]){
                flag = 0;
            }
        }
        if(sum > l){
            flag = 0;
        }
        cout << "Case " << caseCounter++ << ": ";
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }
    return 0;
}
