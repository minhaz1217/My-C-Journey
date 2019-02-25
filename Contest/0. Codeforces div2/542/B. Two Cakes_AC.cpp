/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 24 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long int mabs(long long int a){
    if(a<0){
        return (a*-1);
    }else{
        return a;
    }
}
int main(){

    long long int n,a,sum,b,c1,c2,sPos,dPos;
    vector<pair<long long int,long long int> > vec;
    cin >> n;
    for(int i=0;i<2*n;i++){
        cin >> a;
        vec.push_back(make_pair(a,i));
    }
    sort(vec.begin(), vec.end());
    sum = vec[0].second + vec[1].second;
    sPos = vec[0].second;
    dPos = vec[1].second;

    for(int i=2;i<2*n;i+=2){
        //msg(sPos, dPos)
        a = vec[i].second;
        b = vec[i+1].second;
        c1 = mabs( (a-sPos) ) + mabs( (b-dPos) );
        c2 = mabs( (b-sPos) ) + mabs( (a-dPos) );
        sum += min(c1,c2);
        if(c1<=c2){
            sPos = a;
            dPos = b;
        }else{
            sPos = b;
            dPos = a;
        }
    }
    cout << sum << endl;
    return 0;
}
