/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 53. Maximum Subarray
Problem Link: https://leetcode.com/problems/maximum-subarray/
Date : 08-Jul-2022

Comment: Basic kadane's algorithm.
*/

public class Solution {
    public int MaxSubArray(int[] nums) {
        var arr = nums.ToList();
        int currSum = 0, maxSum = int.MinValue;
        for(int i=0;i<arr.Count;i++){
            currSum += arr[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
}
