/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 190. Reverse Bits
Problem Link: https://leetcode.com/problems/reverse-bits/
Complexity: O(n)
Date : 12 / Jul / 2022

Comment:
*/

public class Solution {
    public uint reverseBits(uint n) {
        var reersedBinaryString = new string( Convert.ToString(n,2).PadLeft(32,'0').Reverse().ToArray());
        var output = Convert.ToUInt32(reersedBinaryString,2);
        return output;
    }
}
