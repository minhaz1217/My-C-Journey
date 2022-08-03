/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 572. Subtree of Another Tree
Problem Link: https://leetcode.com/problems/subtree-of-another-tree/
Complexity: O(n*m) where m is the matching value.
Date : 03 / Aug / 2022

Comment:
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


    public bool CheckSubTree(TreeNode root, TreeNode subRoot) {
        if(root == null && subRoot != null){
            return false;
        }else if(subRoot == null && root != null){
            return false;
        }else if(root == null && subRoot == null){
            return true;
        }

        if(root.val != subRoot.val ){
            return false;
        }

        return CheckSubTree(root.left, subRoot.left) && CheckSubTree(root.right, subRoot.right);
    }

    public bool IsSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null){
            return false;
        }

        if(root.val == subRoot.val){
            return CheckSubTree(root, subRoot) == true ? true : (IsSubtree(root.left, subRoot) || IsSubtree(root.right, subRoot));
        }

        return IsSubtree(root.left, subRoot) || IsSubtree(root.right, subRoot);
    }
}
