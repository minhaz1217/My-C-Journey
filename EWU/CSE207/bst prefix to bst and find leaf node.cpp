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
void findLeafNode(Node *tree){
    if(tree == NULL){
            return;
    }else if(tree->l == NULL && tree->r == NULL){
        cout << "Found a leaf node at "<< tree->data << endl;
        return;
    }
    findLeafNode(tree->l);
    findLeafNode(tree->r);

}


int main(){
    int a = 5,num,i;
    head = NULL;
    cout << "Enter number of nodes: ";
    cin >> a;
    if(a > 0){
        cout << "Enter data for 1th node: ";
        cin >> num;
        head = createTree(head, num);
        for(i =2;i<=a;i++){

            cout << "Enter data for "<<i<<"th node: ";
            cin >> num;
            createTree(head, num);
        }
    }




    cout << "prefix" << endl;
    prefix(head);
    cout << "postfix" << endl;
    postfix(head);
    cout << "infix" << endl;
    infix(head);

    cout << "\n Leaf Node Search: " << endl;
    findLeafNode(head);
    //cout << head->l->data << endl;
}
