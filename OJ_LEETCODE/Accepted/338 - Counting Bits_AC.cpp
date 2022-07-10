/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 338. Counting Bits
Problem Link: https://leetcode.com/problems/counting-bits/
Complexity: Best is O(n)
Date : 10 / Jul / 2022

Comment: there are 5 different solution including Brian Karnighan's algorithm and a dp solution.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;


        // // Solution 1 O(n*64): Using __builtin_popcount()
        // for(int i=0;i<=n;i++){
        //     int count = __builtin_popcount(i);
        //     output.push_back(count);
        // }

        // // Solution 2 O(n*32): Using bitset
        // for(int i=0;i<=n;i++){
        //     bitset<32> b(i);
        //     output.push_back(b.count());
        // }

        // // Solution 3 O(n*32) : Using bit manipulation
        // for(int i=0;i<=n;i++){
        //     int k=i;
        //     int count = 0;
        //     while(k){
        //         count += k%2; // we can further optimize it using k&1
        //         k = k>>1; // we can also do k=k/2;
        //     }
        //     output.push_back(count);
        // }

        // // Solution 4 O(nlog(n)) : Using Brian Kernighan's algorithm
        // for(int i=0;i<=n;i++){
        //     int k=i;
        //     int count = 0;
        //     while(k){
        //         k = k & (k-1);
        //         count++;
        //     }
        //     output.push_back(count);
        // }


        // // Solution 5 O(n): Using DP, in sol 3, we doing last bit of k and then reducing k to k/2, but in dp we've already calculated value of k/2 in the memo, so we are using that.
        vector<int> memo;
        memo.push_back(0);
        output.push_back(0);
        for(int i=1;i<=n;i++){
            int count = memo[i/2] + i%2;
            memo.push_back( count );
            output.push_back(count);
        }


        return output;
    }
};

int main(){
    _INIT;

    return 0;
}
