/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/
Date : 06 / July / 2021
Comment: easy counting problem.
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
/*
2
1 9
output: 1
4
100 100 3 7
output: 1
10
3 3 3 3 5 5 5 2 2 7
output : 2
5
1 1 1 1 1
output : 1
4
1 2 3 4
output : 2
*/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        vector<pair<int,int> > vec;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = 1;
            }else{
                mp[ arr[i] ]++;
            }
        }
        for(map<int,int>::iterator it = mp.begin();it!= mp.end();it++){
            vec.push_back( make_pair(it->second, it->first) );
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int count = 0, numberCount=0;
        for(int i=0;i<vec.size();i++){
            count += vec[i].first;
            numberCount++;
            if(count >= arr.size()/2){
                break;
            }
        }
        return numberCount;
    }
};
int main(){
    int n,a;
    vector<int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    Solution solution;
    cout << solution.minSetSize(vec) << endl;


    return 0;
}
