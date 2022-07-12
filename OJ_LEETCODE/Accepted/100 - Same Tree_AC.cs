/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 100. Same Tree
Problem Link: https://leetcode.com/problems/same-tree/
Complexity: O(n) node number
Date : 12 / Jul / 2022

Comment: Just compare both the nodes at the same time.
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null){
            return true;
        }

        if(p == null || q==null){
            return false;
        }

        if(p.val != q.val){
            return false;
        }
        return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}
