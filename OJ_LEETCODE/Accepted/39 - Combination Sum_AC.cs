/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 39. Combination Sum
Problem Link: https://leetcode.com/problems/combination-sum/
Complexity: O( n2k )
Date : 09 / Jul / 2022

Comment: Normal backtracking problem.
*/


public class Solution {

    int goal;
    IList<int> candidateList;
    IList<IList<int> > output;

    void MakeTarget(IList<int> currentList , int currentSum, int startingPos){

        if(currentSum == goal){
            // we'll insert this list in a list.
            output.Add(currentList);
            return;
        }else if(currentSum > goal || startingPos >= candidateList.Count){
            return;
        }

        for(int i=0;i*candidateList[startingPos] + currentSum<= goal;i++ ){
            var newList = new List<int>(currentList);
            var newSum = currentSum;
            for(int j=0;j<i;j++){
                newList.Add(candidateList[startingPos]);
                newSum += candidateList[startingPos];
            }
            var listToSend = new List<int>(newList);
            MakeTarget(listToSend,newSum, startingPos + 1);
        }
    }
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        goal = target;
        candidateList = candidates.ToList();
        output = new List<IList<int> >();
        var list = new List<int>();
        MakeTarget(list,0,0);
        return output;
    }
}
