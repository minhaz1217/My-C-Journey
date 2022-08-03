/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 56. Merge Intervals
Problem Link: https://leetcode.com/problems/merge-intervals/
Complexity: O(nLog(n))
Date : 03 / Aug / 2022

Comment: Sort and then check conflict linearly.
*/

public class Comparator : IComparer<int[]>{
    public int Compare(int[] a, int[] b){
        if(a[0] == b[0]){
            return a[1].CompareTo(b[1]);
        }
        return a[0].CompareTo(b[0]);
    }
}

public class Solution {
    public bool Conflicts(int[] intervalA, int[] intervalB ){
        if( (intervalA[0] >= intervalB[0] && intervalA[0] <= intervalB[1]) ||
           (intervalA[1] >= intervalB[0] && intervalA[1] <= intervalB[1]) ||
           (intervalB[0] >= intervalA[0] && intervalB[0] <= intervalA[1]) ||
           (intervalB[1] >= intervalA[0] && intervalB[1] <= intervalA[1])){
            return true;
        }
        return false;
    }

    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, new Comparator());
        for(int i=0;i<intervals.Length;i++){
            Console.WriteLine($"{intervals[i][0]} {intervals[i][1]}");
        }
        var outputs = new List<int[]>();
        int start = int.MaxValue;
        int end = int.MinValue;
        for(int i=1;i<intervals.Length;i++){
            if(!Conflicts(intervals[i],intervals[i-1])){
                Console.WriteLine("HI 1");
                if(start != int.MaxValue && end != int.MinValue){
                    int[] arr = new int[2];
                    arr[0] = start;
                    arr[1] = end;
                    outputs.Add(arr);
                    start = int.MaxValue;
                    end = int.MinValue;
                }else{
                    outputs.Add(intervals[i-1]);
                }
            }else{
                Console.WriteLine("HI 2");
                start = Math.Min( start, Math.Min(intervals[i-1][0], intervals[i][0]) );
                end = Math.Max( end, Math.Max(intervals[i-1][1], intervals[i][1]) );
            }
        }
        if(start != int.MaxValue && end != int.MinValue){
            int[] arr = new int[2];
            arr[0] = start;
            arr[1] = end;
            outputs.Add(arr);
            start = int.MaxValue;
            end = int.MinValue;
        }else{
            outputs.Add( intervals[ intervals.Length-1 ] );
        }
        return outputs.OrderBy(x=>x[0]).ToArray();
    }
}
