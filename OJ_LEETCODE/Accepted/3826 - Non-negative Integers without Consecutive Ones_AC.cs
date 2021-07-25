/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3826/
Date : 25 / July / 2021
Comment: the same problem, I submitted in C++, it gave TLE but passed all tests, now in C#, it worked.
*/

public class Solution {

    public int num;
    public int make(int b){
        if(b > num){
            return 0;
        }
        if((b&1) == 1){
            return 1 + make((b<<1));
        }else{
            return 1 + make((b<<1)) + make(((b<<1)|1));
        }
    }

    public int FindIntegers(int n) {
        num = n;
        return make(1)+1;

    }
}
