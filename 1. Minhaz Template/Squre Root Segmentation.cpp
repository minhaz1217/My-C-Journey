/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / January / 2020
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

vector<long long int> a;
vector<long long int> b;
int len;
void srs_init(){
    len = (int) sqrt (a.size() + .0) + 1;
    b.assign(len,0);
    for (int i=0; i<a.size(); ++i)
        b[i / len] += a[i];
}
/// 0 based indexing
long long int srs_query(int l, int r){
    long long int sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
        for (int i=l; i<=r; ++i)
            sum += a[i];
    else {
        for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
            sum += a[i];
        for (int i=c_l+1; i<=c_r-1; ++i)
            sum += b[i];
        for (int i=c_r*len; i<=r; ++i)
            sum += a[i];
    }
    return sum;
}
int main(){
    long long int n,m,x,l,r;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    srs_init();
    while(m--){
        cin >> l >> r;
        cout << srs_query(l,r) << endl;
    }
    return 0;
}
