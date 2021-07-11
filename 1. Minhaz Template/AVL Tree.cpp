/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 11 / July / 2021
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
    AVL tree is a height balanced binary tree. It can insert, search, delete a node in O(H) time. Where H is the height of the tree.

    The base notation is that, we'll at first add or delete a node normally, then if the tree becomes imbalanced, we'll balance that node.

    Let w be the node to be deleted
    1) Perform standard BST delete for w.
    2) Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the larger height child of z, and x be the larger height child of y. Note that the definitions of x and y are different from insertion here.
    3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z. There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways. Following are the possible 4 arrangements:
        a) y is left child of z and x is left child of y (Left Left Case)       Solution > Rotate right
        b) y is left child of z and x is right child of y (Left Right Case)     Solution > Rotate left, rotate right.
        c) y is right child of z and x is right child of y (Right Right Case)   Solution > Rotate left.
        d) y is right child of z and x is left child of y (Right Left Case)     Solution > Rotate right, rotate left.

    ** by definition, BST doesn't allow duplicate value.
    ** If a problem has more searches than add, use AVL tree, if a problem has more ADD/Delete then use Red-Black tree.
*/


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
                cout << root->key << "(" << ") ";
                preOrderUtil(root->left);
                preOrderUtil(root->right);
            }
        }
        void preOrder(){
            preOrderUtil(this->root);
            cout << endl;
        }
};






int main()
{
//    Node *root = NULL;
//
//    /* Constructing tree given in
//    the above figure */
//    root = insert(root, 10);
//    root = insert(root, 20);
//    root = insert(root, 30);
//    root = insert(root, 40);
//    root = insert(root, 50);
//    root = insert(root, 25);

    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrder();
    /* The constructed AVL Tree would be
        30
        / \
        20 40
        / \ \
        10 25 50
    */
    cout << endl;
    tree.preOrder();

    return 0;
}
