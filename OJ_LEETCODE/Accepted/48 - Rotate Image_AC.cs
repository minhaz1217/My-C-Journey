/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 48. Rotate Image
Problem Link: https://leetcode.com/problems/rotate-image/
Complexity: O(n2)
Date : 10 / Jul / 2022

Comment: Transpose and then reverse the matrix. To not use another matrix.
*/

public class Solution {

    public void Swap(ref int a, ref int b){
        var temp = a;
        a = b;
        b = temp;
    }
    public void Rotate(int[][] matrix) {
        int n=matrix.Length;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                Swap(ref matrix[i][j],ref matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            matrix[i] = matrix[i].Reverse().ToArray();
        }
    }
}
