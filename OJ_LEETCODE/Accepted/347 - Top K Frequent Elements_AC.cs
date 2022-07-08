/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 347. Top K Frequent Elements
Problem Link: https://leetcode.com/problems/top-k-frequent-elements/
Complexity: O(nlog(n)))
Date : 09 / Jul / 2022



Comment: Using frequency count and a priority queue. Can optimize further using counting sort.
*/

public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        Dictionary<int,int> numsCount = new Dictionary<int,int>();
        var output = new List<int>();
        foreach(var num in nums){
            if(numsCount.ContainsKey(num)){
                numsCount[num]++;
            }else{
                numsCount[num] = 1;
            }
        }

        var priority = new PriorityQueue<int,int>();

        foreach(var (key,val) in numsCount){
            priority.Enqueue(key,-1* val);
        }

        for(int i=0;i<k;i++){
            output.Add( priority.Dequeue() );
        }
        return output.ToArray();
    }
}
