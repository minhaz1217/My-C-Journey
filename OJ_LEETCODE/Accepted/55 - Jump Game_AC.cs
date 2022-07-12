/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 55. Jump Game
Problem Link: https://leetcode.com/problems/jump-game/
Complexity: O(n), O(1)
Date : 11 / Jul / 2022

Comment: The trick is the "Maximum" jump part.
*/

public class Solution {

    public bool CanJump(int[] nums) {

        int maxDist = 0;
        for(int i=0;i<nums.Length;i++){
            // Console.WriteLine($"{i} {maxDist}");
            if(i > maxDist){
                return false;
            }
            if(i + nums[i] > maxDist){
                maxDist = i + nums[i];
            }
        }
        return true;
    }
}
