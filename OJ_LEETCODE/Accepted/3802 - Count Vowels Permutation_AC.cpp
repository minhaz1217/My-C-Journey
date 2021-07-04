/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3802/
Date : 04 / July / 2021
Comment: normal mod problem. not sure why it is leetcode hard.
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
    int countVowelPermutation(int n) {
        long long mat[30];
        long long aCount,eCount,iCount, oCount, uCount;
        for(int i=0;i<28;i++){
            mat[27] = 0;
        }
        mat['a'-'a'] = 1;
        mat['e'-'a'] = 1;
        mat['i'-'a'] = 1;
        mat['o'-'a'] = 1;
        mat['u'-'a'] = 1;

        for(int i=1;i<n;i++){
            aCount = (mat['e' - 'a']% 1000000007 + mat['i' - 'a']% 1000000007+ mat['u' - 'a']% 1000000007)% 1000000007;
            eCount = (mat['a' - 'a']% 1000000007 + mat['i' - 'a']% 1000000007)% 1000000007;
            iCount = (mat['e' - 'a']% 1000000007 + mat['o' - 'a']% 1000000007)% 1000000007;
            oCount = mat['i' - 'a']% 1000000007;
            uCount = (mat['i' - 'a']% 1000000007 + mat['o' - 'a']% 1000000007)% 1000000007;
            mat['a' -'a'] = aCount;
            mat['e' -'a'] = eCount;
            mat['i' -'a'] = iCount;
            mat['o' -'a'] = oCount;
            mat['u' -'a'] = uCount;
        }
        return (mat['a' - 'a']% 1000000007 + mat['e' - 'a']% 1000000007 + mat['i' - 'a']% 1000000007 + mat['o' - 'a']% 1000000007 + mat['u' - 'a']% 1000000007)% 1000000007;
    }
};
int main(){

    int n;
    cin >> n;
    Solution solution;
    cout << solution.countVowelPermutation(n) << endl;
    return 0;
}
