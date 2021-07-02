/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/
Date : 02 / July / 2021
Comment: very easy problem, not sure why it is marked as medium difficulty.
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
5 4 3
1 2 3 4 5
4 4 -1
1 2 3 4 4 4 4 4 4 4 4 4
12 4 4
1 2 3 4 4 4 4 4 4 4 4 4
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        vector<pair<int,int> > diff;
        for(int i=0;i<arr.size();i++){
            diff.push_back( make_pair( abs(x-arr[i]) , arr[i] ) );
        }


        sort(diff.begin(),diff.end());
        for(int i=0;i<k;i++){
            result.push_back(diff[i].second);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
int main(){
    int a,n,k,x;
    vector<int> vec;
    cin >> n >> k >> x;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    Solution solution;
    vector<int> result =  solution.findClosestElements(vec,k,x);
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
