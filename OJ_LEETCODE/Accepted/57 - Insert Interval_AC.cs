/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 57. Insert Interval
Problem Link: https://leetcode.com/problems/insert-interval/
Complexity:
Date : 02 / Aug / 2022

Comment: Just check for conflicts and insert the beginning and end.
*/

public class Solution {
    public bool Conflicts(int[] oldInterval, int[] newInterval){
        if((newInterval[0] >= oldInterval[0] && newInterval[0] <= oldInterval[1]) ||
           (newInterval[1] >= oldInterval[0] && newInterval[1] <= oldInterval[1]) ||

           (oldInterval[0] >= newInterval[0] && oldInterval[0] <= newInterval[1]) ||
           (oldInterval[1] >= newInterval[0] && oldInterval[1] <= newInterval[1])
          ){
            return true;
        }
        return false;
    }

    public int[][] Insert(int[][] intervals, int[] newInterval) {
        var outputs = new List<int[]>();
        int start = int.MaxValue, end = int.MinValue;
        for(int i=0;i<intervals.Length;i++){
            if(!Conflicts( intervals[i], newInterval )){
                outputs.Add(intervals[i]);
            }else{
                start  = Math.Min(start, Math.Min(intervals[i][0], newInterval[0]));
                end = Math.Max(end, Math.Max(intervals[i][1], newInterval[1]));
            }
        }

        if(start == int.MaxValue && end == int.MinValue){
            int[] makeNew = new int[2];
            makeNew[0] = newInterval[0];
            makeNew[1] = newInterval[1];
            outputs.Add(makeNew);
        }else if(start == int.MaxValue){
            int[] makeNew = new int[2];
            makeNew[0] = newInterval[0];
            makeNew[1] = end;
            outputs.Add(makeNew);
        }else if(end == int.MinValue){
            int[] makeNew = new int[2];
            makeNew[0] = start;
            makeNew[1] = newInterval[1];
            outputs.Add(makeNew);
        }else if(start != int.MaxValue && end != int.MinValue){
            int[] makeNew = new int[2];
            makeNew[0] = start;
            makeNew[1] = end;
            outputs.Add(makeNew);
        }
        return outputs.OrderBy(x=>x[0]).ToArray();
    }

}
