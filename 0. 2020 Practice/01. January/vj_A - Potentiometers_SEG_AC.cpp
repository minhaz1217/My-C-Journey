/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/352689#problem/A
Date : 27 / January / 2020
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

//Segment TREE
#define M 200400
int tree[M*3];
int prop[M*3];
int arr[M];
void init(int nod, int b, int e){
    if(b == e){
        tree[nod] = arr[b];
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);
    tree[nod] = tree[left] + tree[right];
}
void update(int nod, int b, int e, int i, int j, int val){
    if(i > e || j < b){
        return;
    }
    if(b>=i && e<=j){
        tree[nod] = val;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    update(left, b,mid,i,j,val);
    update(right, mid+1, e, i,j,val);
    tree[nod] = tree[left] + tree[right];
}
int query(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return 0;
    }
    if(b >= i && e<=j){
        return tree[nod];
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    int p1 = query(left, b,mid,i,j);
    int p2 = query(right, mid+1, e, i,j);
    return p1+p2;
}

int main(){
    _INIT;
    long long int n,l,r,caseCounter = 1;
    string str;
    while(1){
        cin >> n;
        if(n ==0){
            break;
        }
        if(caseCounter>1){
            cout << endl;
        }
        cout << "Case " << caseCounter++ << ":"<< endl;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }

        init(1,1,n);
        while(1){
            cin >> str;
            if(str== "END"){
                break;
            }
            cin >> l >> r;
            if(str == "M"){
                cout << query(1,1,n,l,r) << endl;
            }else{
                update(1,1,n,l,l,r);
            }
        }
    }

    return 0;
}
