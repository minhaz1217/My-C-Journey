/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 128. Longest Consecutive Sequence
Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
Complexity: O(nLog(n)), could've done it using O(n) using hashmap and visited array, or bucket sorting.
Date : 12 / Jul / 2022

Comment: Sort the number and use kadane's algorigthm. Or Compress the number and bucket sort then kadane's algorithm.
*/
public class Solution {
    public int LongestConsecutive(int[] nums) {
        if(nums.Length == 0){
            return 0;
        }

        Array.Sort(nums);
        nums = nums.Distinct().ToArray();
        var previousNumber = nums[0];
        var maxConsecutiveSequence = 1;
        var currentHighestSequence = 1;
        for(int i=1;i<nums.Length;i++){
            if(previousNumber + 1 == nums[i] ){
                currentHighestSequence++;
            }else{
                currentHighestSequence = 1;
            }

            maxConsecutiveSequence  = Math.Max( maxConsecutiveSequence, currentHighestSequence );
            previousNumber = nums[i];
        }
        return maxConsecutiveSequence;
    }
}
