/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 26 / July / 2021
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

/*
5
1 2 3 4 5


[-10,-3,0,5,9]
[0,-3,9,-10,null,5]

[1,2,3,4,5]
[3,2,5,1,null,4]
*/

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Node{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};


class AVL{
private:
    // get height of the tree
    int height(Node *N){
        if (N == NULL){
            return 0;
        }
        return N->height;
    }

    int max(int a, int b){
        return (a > b)? a : b;
    }

    Node* newNode(int key){
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; // new node is initially added at leaf
        return(node);
    }

    Node *rightRotate(Node *y){
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    Node *leftRotate(Node *x){
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;


        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(Node *N)
    {
        if (N == NULL){
            return 0;
        }
        return height(N->left) - height(N->right);
    }

    // Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree.
    Node* insertNewValue(Node* node, int key){
        /* 1. Perform the normal BST insertion */
        if (node == NULL){
            return(newNode(key));
        }

        if (key < node->key){
            node->left = insertNewValue(node->left, key);
        }else if (key > node->key){
            node->right = insertNewValue(node->right, key);
        }else{
            return node;
        }

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left), height(node->right));

        /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key){
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key){
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
public:
    Node *root;

    AVL(){
        root = NULL;
    }

    void insert(int value){
        this->root = this->insertNewValue(this->root, value);
    }


    // A utility function to print preorder traversal of the tree. The function also prints height of every node
    void preOrderUtil(Node *root)
    {
        if(root != NULL)
        {
            cout << root->key << " ";
            preOrderUtil(root->left);
            preOrderUtil(root->right);
        }else{
            cout << "NULL" << " ";
        }
    }
    void preOrder(){
        preOrderUtil(this->root);
        cout << endl;
    }
};

class Solution {
public:

    TreeNode* cpy(Node* node2){
        if(node2 == NULL){
            return NULL;
        }

        TreeNode* node;
        node = new TreeNode(node2->key);
        node->left = cpy(node2->left);
        node->right = cpy(node2->right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        AVL avl;
        for(int i=0;i<nums.size();i++){
            avl.insert(nums[i]);
        }

        TreeNode *node;
        node = cpy(avl.root);
        return node;
    }
};

void pre(TreeNode* node){
    if(node != NULL){
        cout << node->val << " ";
        pre(node->left);
        pre(node->right);
    }
}

int main(){

    int n,a;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    Solution solution;
    TreeNode* node = solution.sortedArrayToBST(vec);
    pre(node);
    return 0;
}
