/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://abc107.contest.atcoder.jp/tasks/arc101_a?lang=en
Date : 18 / May / 2019
Comment: sliding minimum / maximum range query problem
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

vector<pair< long long int, long long int> > res;
vector<long long int> vec;
void sliding_window(int m){
    int val;
    deque<pair<long long int, long long int> > dqMin, dqMax;
    for(int i=0;i<vec.size();i++){
        val = vec[i];
        while(!dqMin.empty() && dqMin.front().first >= val){
            dqMin.pop_front();
        }
        dqMin.push_front(make_pair(val,i));
        while(!dqMin.empty() && dqMin.back().second <= i-m){
            dqMin.pop_back();
        }


        while(!dqMax.empty() && dqMax.front().first <= val){
            dqMax.pop_front();
        }
        dqMax.push_front(make_pair(val,i));
        while(!dqMax.empty() && dqMax.back().second <= i-m){
            dqMax.pop_back();
        }

        if(i>=m-1){
            res.push_back(make_pair(dqMin.back().first, dqMax.back().first) );
        }
    }
}


int main(){

    long long int n,k,a,ans,mn = INT_MAX,u,v;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sliding_window(k);
    for(int i=0;i<res.size();i++){
        u = res[i].first;
        v = res[i].second;

        if( (u <= 0 && v<= 0) || (u>=0 && v>=0)){
            ans = max(abs(u), abs(v));
        }else{
            ans = min( abs(u), abs(v) )*2 + max( abs(u), abs(v) );
        }
        mn = min(ans,mn);
        //msg2(u,v,mn)
    }
    cout << mn << endl;
    return 0;
}
