/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 11. Container With Most Water
Problem Link: https://leetcode.com/problems/container-with-most-water/
Complexity: O(n)
Date: 09 / Jul / 2022

Comment: Used two pointer and move the pointer of the lower height.
*/

public class Solution {
    public int MaxArea(int[] height) {

        int left = 0, right = height.Length-1, currentSum, maxSum = 0;
        while(left <= right){
            currentSum = ( right - left ) * Math.Min(height[left], height[right]);
            maxSum = Math.Max(currentSum, maxSum);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxSum;
    }
}
