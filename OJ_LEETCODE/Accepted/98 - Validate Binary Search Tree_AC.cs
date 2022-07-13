/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 98. Validate Binary Search Tree
Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
Complexity: O(nLog(n))
Date : 09 / Jul / 2022

Comment: Search that the current node's immediate children is ok and current node is where it is supposed to be.
            Another solution is to calculate currentMin and currentMax and current node should be less than max and more than min.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

    public TreeNode Find(TreeNode node, int target){
        if(node == null){
            return null;
        }

        if(node.val == target){
            return node;
        }else if(target > node.val){
            return Find(node.right, target);
        }else{
            return Find(node.left, target);
        }
    }
    public bool IsValid(TreeNode root, TreeNode currentNode){

        if(currentNode == null){
            return true;
        }

        if(currentNode.left != null && currentNode.left.val >= currentNode.val ){
            return false;
        }else if(currentNode.right != null && currentNode.right.val <= currentNode.val){
            return false;
        }else if(Find(root, currentNode.val) != currentNode){
            return false;
        }

        return IsValid(root, currentNode.left) && IsValid(root, currentNode.right);
    }
    public bool IsValidBST(TreeNode root) {
        return IsValid(root, root);
    }
}
