/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3792/
Date : 26 / June / 2021
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

// 5 2 6 1
// result: 2 1 1 0
// 4 11 7 8 18 3 13 19 15 12
// 1 3 1 1 4 0 1 2 1 0
vector<int>a;
    int Rq, Lq, sum = 0,up;

    pair<pair<int,int> ,int> tree[400004];


    void build(int nod, int l, int r){

        if(l==r){
            tree[nod].first.first = a[l];
            tree[nod].first.second = a[l];
            tree[nod].second= 1;
            return;
        }
        int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
        build(left, l, mid);
        build(right, mid+1, r);
        tree[nod].first.second = min(tree[left].first.second, tree[right].first.second);
        if(tree[left].first.first == tree[right].first.first){
            tree[nod].first.first = tree[left].first.first;
            tree[nod].second = tree[left].second + tree[right].second;
        }else if(tree[left].first.first > tree[right].first.first){
            tree[nod].first.first = tree[left].first.first;
            tree[nod].second= tree[left].second;
        }else{
            tree[nod].first.first = tree[right].first.first;
            tree[nod].second= tree[right].second;
        }
        return;
    }
    int findLowerValueCount(int nod, int l, int r,int findVal){
//        msg4(l,r,Lq,Rq, findVal)
        int count = 0;
        if(r<Lq || l >Rq || l > r){
            return 0;
        }
        if( l>=Lq && r <=Rq){
            if(findVal > tree[nod].first.first ){
                return r-l+1;
            }else if(findVal <= tree[nod].first.second || l==r){
                return 0;
            }else if(findVal == tree[nod].first.first ){
                return abs(r-l+1- tree[nod].second );
            }
        }
        int left = nod*2, right = nod*2 + 1, mid = (l+r)/2;
        int countA = findLowerValueCount(left, l, mid,findVal);
        int countB = findLowerValueCount(right, mid+1, r,findVal);
        return countA + countB;
    }

int main(){

    int b;
    vector<int> result;
    a.push_back(INT_MIN);
    while(cin >> b){
        a.push_back(b);
    }
    build(1, 1, a.size()-1);
//    for(int i=0;i<10;i++){
//        cout << tree[i] << " ";
//    }
//    cout << endl;
    for(int i=1;i<a.size()-1;i++){
        Lq = i+1;
        Rq = a.size()-1;
        result.push_back(findLowerValueCount(1, 1,a.size()-1,a[i]));
    }
    result.push_back(0);

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
