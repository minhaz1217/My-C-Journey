/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 33. Search in Rotated Sorted Array
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
Complexity: O(logN)
Date : 11 / Jul / 2022

Comment: Binary search considering the pivot
*/

public class Solution {
    int pos = -1;
    public bool TargetIsPresentInThisRange(int[] nums, int target, int left, int right){
        if(left > right){
            return false;
        }else if(left == right && nums[left] != target){
            return false;
        }

        // Console.WriteLine($"{left} {right} {target}");

        if( (nums[left] < nums[right]  && target >= nums[left] && target <= nums[right]) ){
            // Console.WriteLine($"Flase 1 : {left} {right} {target}");
            return true;
        }else if((nums[left] > nums[right]  && (target >= nums[left] || target <= nums[right])) ){
            // Console.WriteLine($"False 2: {left} {right} {target}");
            return true;
        }
        return false;
    }

    public bool Find(int[] nums, int target, int left, int right){
        if(left > right){
            return false;
        }
        if(nums[left] == target){
            pos = left;
            return true;
        }else if(nums[right] == target){
            pos = right;
            return true;
        }

        var mid = left + (right - left)/2;
        if(nums[mid] == target){
            pos = mid;
            return true;
        }
        // Console.WriteLine($"{left} {right} {mid}");

        return (TargetIsPresentInThisRange(nums, target, left, mid) && Find(nums, target, left, mid))
            || (TargetIsPresentInThisRange(nums, target, mid+1, right) && Find(nums, target, mid+1, right));
    }

    public int Search(int[] nums, int target) {
        Find(nums, target, 0, nums.Length - 1);
        return pos;
    }
}
