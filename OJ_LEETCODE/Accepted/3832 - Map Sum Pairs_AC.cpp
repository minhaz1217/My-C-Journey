/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 30 / July / 2021
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
class MapSum {
public:
    map<string, int> mp;
    MapSum() {
        mp.clear();
    }

    void insert(string key, int val) {
        mp[key] = val;
    }

    bool find(string str1, string patt){
        int sz1 = str1.size(), sz2 = patt.size();
        if(sz2 > sz1){
            return false;
        }
        for(int i=0;i< sz2;i++){
            if(str1[i] != patt[i]){
                return false;
            }
        }
        return true;
    }

    int sum(string prefix) {
        int counter = 0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if( find(it->first, prefix) ){
                counter += it->second;
            }
        }
        return counter;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(){

    return 0;
}
