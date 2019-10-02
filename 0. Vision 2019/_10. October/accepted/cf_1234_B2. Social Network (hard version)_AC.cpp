/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1234/problem/B2
Date : 02 / October / 2019
Comment: notice that the only thing that gets removed from the list is the last element.
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

bool arr[200005];
int main(){
    long long int n,k,id=1,a;
    deque<long long int> dq;
    map<long long int, int>mp;
    vector<long long int> vec;
    vec.push_back(4);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        if(mp.find(a) == mp.end()){
            mp[a] = id++;
            vec.push_back(a);
        }
        a = mp[a];
        if(arr[a] == 0){
            arr[a] = 1;
            dq.push_front(a);
            if(dq.size() > k){
                arr[dq.back()] = 0;
                dq.pop_back();
            }
        }
//for(int i=0;i<dq.size();i++){
//if(i>0){
//cout << " ";
//}
//cout << dq[i];
//}
//cout << endl;

    }
    cout << dq.size() << endl;
    for(int i=0;i<dq.size();i++){
        if(i>0){
            cout << " ";
        }
        cout << vec[dq[i]];
    }
    cout << endl;

    return 0;
}
