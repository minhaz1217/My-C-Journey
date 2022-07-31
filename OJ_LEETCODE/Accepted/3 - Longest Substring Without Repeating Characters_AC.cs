/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 3. Longest Substring Without Repeating Characters
Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Complexity: O(n)
Date : 31 / Jul / 2022

Comment: Normal sliding window type problem. Keep track of the last found index and start the next index from the last found + 1.
*/



public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var visited = new Dictionary<char, int>();

        int lastStart = 0, counter = 0,longestSubstringLength = 0;
        for(int i=0;i<s.Length;i++){
            if( visited.ContainsKey(s[i]) && visited[s[i]] >= lastStart ){
                lastStart = visited[s[i]]+1;
                counter =  i - lastStart+1;
                visited[s[i]] = i;
                // Console.WriteLine($"{s[i]} {lastStart} {counter} found");
            }else{
                visited[s[i]] = i;
                counter++;
                // Console.WriteLine($"{s[i]} {lastStart} {visited[s[i]]} {counter} not found");
            }
            longestSubstringLength = Math.Max(longestSubstringLength, counter);
        }
        // Console.WriteLine("");
        return longestSubstringLength;
    }
}
/*
Input:
"abcabcbb"
"bbbbb"
"pwwkew"

Output:
3
1
3

*/
