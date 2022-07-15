/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 105. Construct Binary Tree from Preorder and Inorder Traversal
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Complexity: O(n*2)
Date : 09 / Jul / 2022

Comment: The first value that is present in preorder is the root node. That node's location in inorder can determine which nodes are on the left tree and right tree.
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
    public Dictionary<int,int> preOrderPosition;

    public int FindPositionOfNumberWhichCameFirstInInOrder(int[] inOrder, int left, int right){
        int lowestPreOrderPosition = int.MaxValue, inOrderPosition = 0;
        for(int i=left;i<=right;i++){
            if(preOrderPosition[inOrder[i]] < lowestPreOrderPosition){
                lowestPreOrderPosition = preOrderPosition[inOrder[i]];
                inOrderPosition = i;
            }
        }
        return inOrderPosition;
    }
    public TreeNode Build(int[] inOrder, int inOrderLeft, int inOrderRight){
        if(inOrderLeft > inOrderRight){
            return null;
        }
        var headPosition = FindPositionOfNumberWhichCameFirstInInOrder(inOrder, inOrderLeft, inOrderRight);
        var node = new TreeNode();
        node.val = inOrder[headPosition];
        node.left = Build(inOrder, inOrderLeft, headPosition -1);
        node.right = Build(inOrder, headPosition +1, inOrderRight);
        return node;
    }

    public TreeNode BuildTree(int[] preOrder, int[] inOrder) {
        preOrderPosition = new Dictionary<int,int>();
        for(int i=0;i<preOrder.Length;i++){
            preOrderPosition[preOrder[i]] = i;
        }

        var headPosition = FindPositionOfNumberWhichCameFirstInInOrder(inOrder, 0, inOrder.Length-1);
        var node = new TreeNode();
        node.val = inOrder[headPosition];
        node.left = Build(inOrder, 0, headPosition-1);
        node.right = Build(inOrder, headPosition+1, inOrder.Length-1);


        return node;
    }
}
