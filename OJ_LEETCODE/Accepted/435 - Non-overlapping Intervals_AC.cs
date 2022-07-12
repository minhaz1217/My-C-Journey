/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 435. Non-overlapping Intervals
Problem Link: https://leetcode.com/problems/non-overlapping-intervals/
Complexity: O(nLog(n))
Date : 12 / Jul / 2022

Comment: Job scheduling algorithm. Sort the number by the end time and if the end time matches take the start number that is higher (making the gap the shorter).
*/


public class Solution {
    public void Print(int[][] arr){
        for(int i=0;i<arr.Length;i++){
            for(int j=0;j<arr[i].Length;j++){
                Console.Write($"{arr[i][j]} ");
            }
            Console.WriteLine("");
        }
    }

    public class Comparator : IComparer<int[]>
    {
        public int Compare(int[] arr1, int[] arr2 )
        {
            // if both end is same we'll take the smaller start first. so 3,5 will go before 1,5
            if(arr1[1] == arr2[1])
            {
                return arr2[0].CompareTo(arr1[0]);
            }
            return arr1[1].CompareTo(arr2[1]);
        }
    }

    public bool Conflicts(int[] arr1, int[] arr2){
        if((arr1[0] > arr2[0] && arr1[0] < arr2[1]) ||
           (arr1[1] > arr2[0] && arr1[1] < arr2[1]) ||
           (arr1[0] == arr2[0] && arr1[1] == arr2[1])
        ){
            return true;
        }
        return false;
    }
    public int EraseOverlapIntervals(int[][] intervals) {


        Array.Sort(intervals,new Comparator());
        // Print(intervals);
        // Console.WriteLine("");
        var prev = intervals[0];
        int counter = 0;
        for(int i=1;i<intervals.Length;i++){
            if(Conflicts(prev, intervals[i])){
                counter++;
            }else{
                prev = intervals[i];
            }
        }
        return counter;
    }
}
