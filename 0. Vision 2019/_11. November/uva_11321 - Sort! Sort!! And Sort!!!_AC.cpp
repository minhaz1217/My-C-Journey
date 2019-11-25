/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2296
Date : 16 / November / 2019
Comment: got WA because was comparing odd numbers as == 1, but it'll give wrong for modding with negative numbers.
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

bool ccc(pair<long long int, long long int> a, pair<long long int, long long int>  b){
    // 1 means a first, else b first
    if(a.first < b.first){
        return 1;
    }else if(a.first > b.first){
        return 0;
    }
    if(a.second %2 == 0 && b.second%2 == 0){
        if(a.second < b.second){
            return 1;
        }else{
            return 0;
        }
    }else if(a.second %2 != 0 && b.second%2 != 0){
        if(a.second > b.second){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(a.second %2 != 0){
            return 1;
        }else{
            return 0;
        }
    }


}
int main(){

    long long int n,m,a;
    while(1){
        vector<pair<long long int,long long int> > vec;
        scanf("%lld %lld", &n, &m);
        printf("%lld %lld\n",n,m);
        if(n == 0 && m == 0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%lld", &a);
            vec.push_back({a%m,a});
        }
        sort(vec.begin(),vec.end(), ccc);
        for(int i=0;i<vec.size();i++){
            printf("%lld\n",vec[i].second);
        }
    }
    return 0;
}
