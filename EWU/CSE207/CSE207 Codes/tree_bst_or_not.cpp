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
    }else{
        if(tree->l == NULL){

        }
    }

    /*else if(tree->l == NULL){
        tree->l = createTree(tree->l, data);
    }else if(tree->r == NULL){
        tree->r = createTree(tree->r, data);
    }else{

    }
    */
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

int checkIfBST(Node *tree){
    if(tree!= NULL){
        if(tree->r != NULL){
            if(tree->r->data >= tree->data){
                checkIfBST(tree->r);
            }else{
                cout << "Error Found" << endl;
                return 0;
            }
        }else if(tree->l != NULL){
            if(tree->l->data < tree->data){
                checkIfBST(tree->l);
            }else{
                cout << "ERROR FOUND" << endl;
            }
        }
    }
}
int main(){
    int height, nodes,n;
    Node* head;

    cout << "What is the height of the tree: ";
    cin >> height;
    nodes = pow(2,height+1) -1;
    cout << nodes << endl;
    int arr[nodes], i;

    cout << "Enter 0: ";
    cin >> n;
    head = NULL;
    head = createTree(head, n);

    for(i=1;i<nodes;i++){
        cout << "Enter " << i << " :";
        cin >> n;
        createTree(head, n);
    }
    cout << "PREFIX" << endl;
    prefix(head);
    checkIfBST(head);
    return 0;
}
