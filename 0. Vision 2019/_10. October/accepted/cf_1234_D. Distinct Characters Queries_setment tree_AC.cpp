/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1234/problem/D
Date : 02 / October / 2019
Comment: normal unique segment tree.
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
#define M 100005
int tree[M*3][26];
int prop[M*3];
int arr[M];
void init(int nod, int b, int e){
    if(b == e){
        tree[nod][arr[b]] = 1;
        return;
    }
    int left = nod*2, right = (nod*2)+1, mid = (b+e)/2;
    init(left, b , mid);
    init(right, mid+1, e);
    for(int i=0;i<26;i++){
        if(tree[left][i] || tree[right][i] ){
            tree[nod][i] = 1;
        }
    }
    //tree[nod] = tree[left] + tree[right];
}
void update(int nod, int b, int e,int i, int j){
    if(i > e || j < b){
        return;
    }
    if(b>=i && e<=j){
//        msg2("UPDATING", nod,arr[i])
        for(int k=0;k<26;k++){
            tree[nod][k] = 0;
        }
        tree[nod][arr[i]] = 1;
        return;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    update(left, b,mid,i,j);
    update(right, mid+1, e, i,j);
    for(int i=0;i<26;i++){
        if(tree[left][i]){
//            msg2("FOUND LEFT",nod,  i)
            tree[nod][i] = 1;
        }else if(tree[right][i]){
//            msg2("FOUND RIGHT", nod, i);
            tree[nod][i] = 1;
        }else{
            tree[nod][i] = 0;
        }
    }
    return;
}
vector<int> query(int nod, int b, int e, int i, int j){
    if(i>e || j < b){
        return vector<int>(26,0);
    }
    if(b >= i && e<=j){
        vector<int>vec;
        for(int i=0;i<26;i++){
            if(tree[nod][i]){
                vec.push_back(1);
            }else{
                vec.push_back(0);
            }
        }
        return vec;
    }
    int left = nod*2, right = nod*2 + 1, mid = (b+e)/2;
    vector<int> p1 = query(left, b,mid,i,j);
    vector<int> p2 = query(right, mid+1, e, i,j);
    vector<int>vec;
    for(int i=0;i<26;i++){
        if(p2[i]){
            p1[i] = 1;
        }
    }
    return p1;
}
int main(){
    string str;
    char x;
    long long int n,a,b,l,r,counter;
    cin >> str;
    cin >> n;
    for(int i=0;str[i];i++){
        arr[i+1] = str[i]-'a';
    }
    init(1,1,str.size());

    for(int i=0;i<n;i++){
        cin >> a;
        if(a == 1){
            cin >> b >> x;
            arr[b] = x -'a';
            update(1,1,str.size(),b,b);
//            for(int i=1;i<=str.size();i++){
//                cout << (char)(arr[i]+'a') << " ";
//            }
//            cout << endl;
        }else{
            cin >> l >> r;
            vector<int>vec = query(1,1,str.size(),l,r);
            counter = 0;
            for(int j=0;j<vec.size();j++){
                if(vec[j]){
//                    msg("FOUND", (char)(j+'a'))
                    counter++;
                }
            }
            cout << counter << endl;

        }

    }
    return 0;
}
