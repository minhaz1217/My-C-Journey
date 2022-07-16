/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 139. Word Break
Problem Link: https://leetcode.com/problems/word-break/
Complexity: O(n*3)
Date : 17 / Jul / 2022

Comment: It is a DP problem but i've solved it using backtracking with memoization. I'm just checking whether i can put a space here in pos and make the rest of the words true or not.
*/
public class Solution {
    Dictionary<string ,bool> dict;
    int[] memo;
    public bool Find(string s, int pos){
        if(pos >= s.Length){
            return true;
        }

        if(memo[pos] != 0){
            return memo[pos] == 2 ? false : true;
        }

        StringBuilder sb = new StringBuilder();
        for(int i=pos;i<s.Length;i++){
            sb.Append(s[i]);
            // Console.WriteLine(sb.ToString());
            if(dict.ContainsKey(sb.ToString())){
                // Console.WriteLine("FOUND");
                memo[pos] = 1;
                if(Find(s, i+1)){
                    return true;
                }
            }
        }
        memo[pos] = 2;
        return false;
    }

    public bool WordBreak(string s, IList<string> wordDict) {
        dict = new Dictionary<string,bool>();
        memo = new int[s.Length+1];
        for(int i=0;i<wordDict.Count;i++){
            dict[wordDict[i]] = true;
        }

        return Find(s,0);
    }
}
