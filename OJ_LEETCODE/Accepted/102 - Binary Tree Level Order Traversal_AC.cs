/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 102. Binary Tree Level Order Traversal
Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Complexity: O(n) where n is the total node number.
Date : 11 / Jul / 2022

Comment: Basic tree traversal.
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
    IList<IList<int> > output;

    public void Traverse(TreeNode root, int level){
        if(root == null){
            return;
        }
        // Console.WriteLine($"{root.val} {level} {output.Count}");
        if(output.Count < level+1){
            output.Add(new List<int>());
        }
        output[level].Add(root.val);
        Traverse(root.left , level + 1);
        Traverse(root.right , level + 1);
    }
    public IList<IList<int>> LevelOrder(TreeNode root) {
        output = new List<IList<int> >();
        Traverse(root, 0);
        return output;
    }
}
