// have to submit with cpp14 clang 4.0 otherwise tle
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
struct node{
    int data;
    node *next, *prev;
};
node *curr,*head, *tail, *prevoftail;
void insertNode(int d){
    curr = new node;
    curr->data = d;
    curr->prev = NULL;
    curr->next = NULL;
    if(head == NULL){
        head = curr;
        tail = curr;
    }else{
        //insert at first
        curr->next = head;
        curr->prev = NULL;
        head->prev = curr;
        head = curr;
    }
}
void bringLastToFirst(){
    if(head != NULL){
        node *tmp = tail;

        curr = new node;
        curr->data = tail->data;
        curr->next = NULL;
        curr->prev = NULL;

        curr->next = head;
        head->prev = curr;
        head = curr;
        tail = tail->prev;
        tail->next = NULL;
        delete(tmp);
    }
}

void display(){
    curr = head;
    while(curr!= NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int atFront(){
    return head->data;
}
void deleteNode(node *tree){
    deleteNode(tree->next);
    delete(tree);
}
int main(){
    head = NULL;
    int currVal = 1;
    int a,i,j,x, tc;
    cin >> tc;
    while(tc--){
        cin >> a;
        currVal = 0;
        head = NULL;
        for(i=a;i>=1;i--){
            insertNode(i);
            currVal++;

            for(j=1;j<=i%currVal;j++){
                //display();
                bringLastToFirst();
            }
        }
        curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    return 0;
}
