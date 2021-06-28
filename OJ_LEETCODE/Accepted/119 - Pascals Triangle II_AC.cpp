/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/problems/pascals-triangle-ii/
Date : 28 / June / 2021
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
    long long int binom[35][35];

    int lasti, lastj;
    bool init;
    Solution(){
        lasti = 0;
        lastj = 0;
        init = false;
    }
    long long int BinomialCoefficient(int n, int k)
    {
        if (lasti >= n && lastj >= k) return binom[n][k];
        if (!init)
        {
            for (int i=0;i<=n;i++) binom[i][0] = 1;
            for (int j=1;j<=k;j++) binom[0][j] = 0;
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=k;j++)
                {
                    binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
                }
            }
            init = true;
            lasti = n;
            lastj = k;
            return binom[n][k];
        }
        else
        {
            if (lastj < k)
            {
                for (int i=1;i<=lasti;i++)
                {
                    for (int j=lastj+1;j<=k;j++)
                    {
                        binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
                    }
                }
                lastj = k;
            }
            if (lasti >= n) return binom[n][k];
            else
            {
                for (int i=lasti+1;i<=n;i++)
                {
                    binom[i][0] = 1;
                    for (int j=1;j<=lastj;j++)
                    {
                        binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
                    }
                }
                lasti = n;
                return binom[n][k];
            }
        }
    }
    vector<int> getRow(int rowIndex) {
        BinomialCoefficient(rowIndex,rowIndex);
        vector<int> result;
        for(int i=0;i<=rowIndex;i++){
            result.push_back(BinomialCoefficient(rowIndex, i));
        }
        return result;
    }
};


int main(){

    return 0;
}
