/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3801/
Date : 03 / July / 2021
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
/*
2 3 2
1 0 1
0 -2 3
output: 2

1 3 3
2 2 -1
output: 3

3 3 50
1 2 3
4 5 6
7 8 9
output: 45
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& mat, int kk) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == kk){
                    return kk;
                }
                if(i>0){
                    mat[i][j] += mat[i-1][j];
                }
                if(j > 0){
                    mat[i][j] += mat[i][j-1];
                }
                if(i > 0 && j > 0){
                    mat[i][j]  -= mat[i-1][j-1];
                }
                if(mat[i][j] == kk){
                    return kk;
                }
            }
        }

        int mx = INT_MIN,subRect = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=i;k<m;k++){
                    for(int l = j;l<n;l++){
                        /// find the rectangle, (i,j), (i+p,j+q), so the 4 corners are (i,j), (i, j+q), (i+p, j), (i+p,j+q)
                        subRect = mat[k][l];
                        if(i > 0){
                            subRect -= mat[i-1][l];
                        }
                        if(j>0){
                            subRect -= mat[k][j-1];
                        }
                        if(i > 0 && j>0){
                            subRect += mat[i-1][j-1];
                        }
                        if(subRect == kk){
                            return kk;
                        }else if(subRect < kk){
                            mx = max(mx, subRect);
                        }
                    }
                }
            }
        }
        return mx;
    }
};

int main(){
    int m,n,k,a;
    vector<vector<int> > mat;
    cin >> m >> n >> k;
    for(int i=0;i<m;i++){
        vector<int> vec;
        for(int j=0;j<n;j++){
            cin >> a;
            vec.push_back(a);
        }
        mat.push_back(vec);
    }
    Solution solution;
    cout << solution.maxSumSubmatrix(mat, k) << endl;
    return 0;
}
