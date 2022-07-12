/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 125. Valid Palindrome
Problem Link: https://leetcode.com/problems/valid-palindrome/
Complexity: O(nLog(n))
Date : 12 / Jul / 2022

Comment: Remove numbers and sort reverse compare.
*/

public class Solution {
    public bool IsPalindrome(string s) {

        var stringBuilder = new StringBuilder();
        for(int i=0;i<s.Length;i++){
            if((s[i] >= 'a' && s[i] <='z') || (s[i] >='A' && s[i] <='Z') || (s[i] >= '0' && s[i] <= '9')){
                stringBuilder.Append( s[i] );
            }
        }
        var s1 = stringBuilder.ToString().ToLower();
        var s2 = (s1.ToArray());
        Array.Reverse(s2);
        var s3 = new String(s2);
        return s1.SequenceEqual(s3);
    }
}
