/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3807/
Date : 08 / July / 2021
Comment: normal n*nlog(n) brute force didn't work for some reason but n*n did.
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
5
1 2 3 2 1
5
3 2 1 4 7
output : 3
5
0 0 0 0 0
5
0 0 0 0 0
output: 5
*/
int mat[1004][1004];
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<1004;i++){
            for(int j=0;j<1004;j++){
                mat[i][j] = 0;
            }
        }
        int mx = 0;
//        cc("REACHED");
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    mat[i+1][j+1] = mat[i][j]+1;
                    mx = max( mx, mat[i+1][j+1] );
                }
            }
        }

        return mx;
    }
};

int main(){
//    for(int i=0;i<1000;i++){
//        cout << 5 << ",";
//    }
//    cout << endl;

    int n,a;
    vector<int>vec1,vec2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec1.push_back(a);
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec2.push_back(a);
    }
//cc("HI2")
    Solution solution;
    cout << solution.findLength( vec1, vec2 ) << endl;


    return 0;
}
