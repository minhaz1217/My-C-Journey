/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 24 / August / 2021
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, int k){
        TreeNode* temp = root;
        while(temp != nullptr){
            if(temp->val == k){
                return true;
            }else if(k > temp->val ){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        return false;
    }
    bool helper(TreeNode* root,TreeNode* node, int k){
        if(node == nullptr){
            return false;
        }
        if(k-node->val == node->val){
            return helper(root, node->left, k) || helper(root, node->right, k);
        }
        return find(root, k-node->val) || helper(root, node->left, k) || helper(root, node->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        return helper(root, root, k);
    }
};
int main(){

    return 0;
}
