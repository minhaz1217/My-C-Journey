/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 70. Climbing Stairs
Problem Link: https://leetcode.com/problems/climbing-stairs/
Complexity:
Date : 15 / Jul / 2022

Comment: At first find the output of 1-5 by hand then see that this problem is only a fibonacci series.
*/
public class Solution {
    public int ClimbStairs(int n) {
        int[] fib = new int[n+2];
        fib[0] = 1;
        fib[1] = 1;
        for(int i=2;i<=n;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
}
