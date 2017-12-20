#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *l, *r;
};
Node *head,*curr, *temp;
Node *createTree(Node *tree, int data){

    if(tree == NULL){
        tree = new Node;
        tree->data = data;
        cout << "Data Entered: " << data << endl;
        tree->l = NULL;
        tree->r = NULL;
    }else if(data >= tree->data){
        tree->r = createTree(tree->r, data);
    }else{
        tree->l = createTree(tree->l, data);
    }
    return tree;
}
void prefix(Node *tree){
    //cout << "call: " << endl;
    if(tree != NULL){
        //cout << "pre" << endl;
        cout << tree->data << endl;
        prefix(tree->l);
        prefix(tree->r);
    }
}
void infix(Node *tree){
    if(tree != NULL){
        infix(tree->l);
        cout << tree->data << endl;
        infix(tree->r);
    }
}
void postfix(Node *tree){
    if(tree != NULL){
        postfix(tree->l);
        postfix(tree->r);
        cout << tree->data << endl;
    }
}

Node* searchBST(int num, Node *tree){
    if(tree->data == num){
        return tree;
    }else if(tree == NULL){
        cout << "Can't find" << endl;
        return NULL;
    }else{
        if(tree->data < num){
            return searchBST(num, tree->r);
        }else{
            return searchBST(num, tree->l);
        }
    }
}

int main(){
    int a = 5,d;
    head = NULL;
    head = createTree(head, 4);
    createTree(head, 3);
    createTree(head, 5);
    createTree(head, 2);
    createTree(head, 1);
    cout << "prefix" << endl;
    prefix(head);
    cout << "postfix" << endl;
    postfix(head);
    cout << "infix" << endl;
    infix(head);
    cout << "\nSearch" << endl;
    Node *curr;
    int findData = 1;
    curr = searchBST(findData, head);
    if(curr->data == findData){
        cout << "Data found" << endl;
    }else{
        cout << "Data Not Found" << endl;
    }
    //cout << head->l->data << endl;
}
