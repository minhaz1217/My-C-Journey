/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-371
Date : 25 / October / 2019
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


long long int  counter = 0;
map<long long int,long long int>mp;
long long int func(long long int  n){
    long long int ans = 0;
    if(n == 1 && counter > 0){
        return 0;
    }
    counter++;
    if(mp.find(n) != mp.end()){
        return mp[n];
    }
    if(n%2 == 0){
        ans= n/2;
    }else{
        ans =3*n + 1;
    }
    return mp[n] = 1+func(ans);
}
int main(){
    long long int x,y,big,mx,ans,a,b;
    counter = 1;
    for(long long int i=2;;i=i*2){
//        msg(i, counter)
        mp[i] = counter;
        counter++;
        if(counter == 32){
            break;
        }
    }
    for(int i=1;i<=100;i++){
        counter = 0;
        //msg(i,func(i));
    }
    mp[1] = 3;
    while(1){
        cin >> a >> b;
        if(a == 0&& b ==0){
            break;
        }
        x = min(a,b);
        y = max(a,b);
        big = x;
        mx = func(x);
        for(long long int i =x;i<=y;i++){
            counter = 0;
            ans = func(i);
            if(ans > mx){
                mx = ans;
                big = i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",x,y,big,mx);

    }


    return 0;
}
