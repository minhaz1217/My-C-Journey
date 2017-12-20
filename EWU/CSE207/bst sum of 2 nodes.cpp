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
        cout << "Data entered: " << data << endl;
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
void sumOf2Nodes(Node *tree, int sum){
    if(tree == NULL){
        return;
    }else if(tree -> l != NULL){
        if(tree->data + tree->l->data == sum){
            cout << "Found" << endl;
            cout << tree->data << "+" << tree->l->data << " = " << sum << endl;
            return;
        }
    }else if(tree-> r != NULL){
        if(tree->data + tree->r->data == sum){
            cout << "Found" << endl;
            cout << tree->data << "+" << tree->r->data << " = " << sum << endl;
            return;
        }
    }
    sumOf2Nodes(tree->r, sum);
    sumOf2Nodes(tree->l, sum);

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
    sumOf2Nodes(head, 7);
    //cout << head->l->data << endl;
}
