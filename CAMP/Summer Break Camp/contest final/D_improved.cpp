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
void bringNLastToFirst(int n){
    curr = head;
    for(int i=1;i<=n;i++){
        curr = curr->next;
    }
    msg(curr->data, head->data)
    tail->next = head;
    head->prev = tail;

    head = curr->next;
    head->prev = NULL;

    curr->next = NULL;
    tail = curr;
}


int atFront(){
    return head->data;
}
void display(){
    curr = head;
    while(curr!= NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void deleteNode(node *tree){
    if(tree == NULL){
        return;
    }
    deleteNode(tree->next);
    delete(tree);
}
int main(){
    head = NULL;
    int a,i,j,x, tc;
    cin >> tc;
    while(tc--){
        cin >> a;
        head = NULL;
        for(i=a;i>=1;i--){display();
            insertNode(i);
            if(a-i+1 > i){
                bringNLastToFirst(i);
            }else{

                for(j=1;j<=i;j++){
                    bringLastToFirst();
                }
            }
        }
        curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        deleteNode(head);
    }
    return 0;
}
