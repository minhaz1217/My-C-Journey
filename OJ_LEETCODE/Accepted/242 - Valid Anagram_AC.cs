/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 242. Valid Anagram
Problem Link: https://leetcode.com/problems/valid-anagram/
Complexity: O(nlogn)
Date : 10 / Jul / 2022

Comment: Sort then compare, or make a frequency array or use map.
*/
public class Solution {
    public bool IsAnagram(string s, string t) {
        var ss = s.ToArray();
        var tt = t.ToArray();
        Array.Sort(tt);
        Array.Sort(ss);
        return tt.SequenceEqual(ss);
    }
}
