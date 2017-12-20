#include<bits/stdc++.h>
using namespace std;





struct node{
    int data;
    node *l, *r;
};

node *head, *curr;

node* insertNode(node *tree, int d){
    if(tree == NULL){
        curr = new node;
        curr->data = d;
        curr->l = NULL;
        curr->r = NULL;
        tree = curr;
    }else if(d >= tree->data){
        tree->r = insertNode(tree->r, d);
    }else if(d < tree->data){
        tree->l = insertNode(tree->l, d);
    }
    return tree;
}
void prefix(node *tree){
    if(tree != NULL){
        cout << tree->data << " ";
        prefix(tree->l);
        prefix(tree->r);
    }
}

void findTheLeafNodes(node *tree){
    if(tree == NULL){
        return;
    }else if(tree->l == NULL && tree->r == NULL){
        cout << tree->data << " is a leaf node." << endl;
    }else{
        findTheLeafNodes(tree->l);
        findTheLeafNodes(tree->r);
    }
}
void calculateNumberOfChild(node *tree){
    int temp;
    if(tree == NULL){
        return;
    }else if(tree->l == NULL && tree->r == NULL){
        printf("Child of node %2d: %2d(%2d )\n", tree->data, 0 ,0);
    }else if(tree->l == NULL || tree->r == NULL){
        if(tree->l == NULL){
            temp = tree->r->data;
        }else{
            temp = tree->l->data;
        }
        printf("Child of node %2d: %2d(%2d )\n", tree->data,1,  temp);
    }else{
        printf("Child of node %2d: %2d(%2d , %2d )\n", tree->data, 2, tree->l->data, tree->r->data);
    }
    calculateNumberOfChild(tree->l);
    calculateNumberOfChild(tree->r);
}


int main(){
    head = NULL;
    head = insertNode(head, 8);
    insertNode(head, 7);
    insertNode(head, 10);
    insertNode(head, 2);
    insertNode(head, 9);
    insertNode(head, 13);
    cout << "Prefix" << endl;
    prefix(head);
    cout << endl;
    cout << "Find the leaf nodes." << endl;
    findTheLeafNodes(head);
    cout << "Find the child node of a tree." << endl;
    calculateNumberOfChild(head);

    //cout << head->data << endl;
    return 0;
}
