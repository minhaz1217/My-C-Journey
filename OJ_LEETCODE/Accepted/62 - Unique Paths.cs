/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 62. Unique Paths
Problem Link: https://leetcode.com/problems/unique-paths/
Complexity: O(n*m) O(n*m)
Date : 10 / Jul / 2022

Comment: Basic DP problem. I've gone from top to bottom, there is another bottom to top solution that starts with 1 as memo.
*/

public class Solution {


    int totalPaths = 0;
    int [,] memo;
    int m, n;
    public int FindUniquePath(int row, int col){
        if(row >= m || col >= n){
            return 0;
        }

        if(memo[row,col] > 0){
            return memo[row,col];
        }
        if(row == m -1 && col == n-1){
            memo[row,col] = 1;
            return memo[row,col];
        }

        memo[row, col] = FindUniquePath(row + 1, col) + FindUniquePath(row, col+1);
        return memo[row,col];
    }
    public int UniquePaths(int mm, int nn) {
        m = mm;
        n = nn;
        memo = new int[m+5,n+5];
        return FindUniquePath(0,0);
    }
}
