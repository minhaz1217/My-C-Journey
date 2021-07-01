/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 01 / July / 2021
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

class Solution {
public:
    map<int,int> mp;
    int totalBits;
    int generateNext(int current){
        bitset<32> a(current);
        vector<int> vec;
        for(int i=0;i<totalBits;i++){
            bitset<32> b = a;
            b.flip(i);
            int num = (int)b.to_ulong();
            if(mp.find(num) == mp.end()){
                return num;
            }
        }
        return current;
    }
    vector<int> grayCode(int n) {
        vector<int> result;
        totalBits = n;
        int sz = pow(2,totalBits);
        result.push_back(0);
        result.push_back(1);
        mp[0] = 1;
        mp[1] = 1;
        for(int i=2;i<sz;i++){
            int nextNumber = generateNext(result[i-1]);
            mp[nextNumber] = 1;
            result.push_back(nextNumber);
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    Solution solution;
    vector<int> vec = solution.grayCode(n);
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
