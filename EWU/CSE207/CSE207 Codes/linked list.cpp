#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

struct Node{
    int data;
    Node *next;
};
Node *head, *curr,*tail;

void display(){
    Node *c,*p;
    c = head;
    while(1){
        cout << c->data << endl;
        if(c->next == NULL){
            break;
        }else{
            c = c->next;
        }
    }
}

int main(){
    curr = (Node *) malloc(sizeof(Node));
    curr->data = 20;
    curr->next = NULL;
    head = curr;
    tail = curr;

    curr = new Node;
    tail->next = curr;
    tail = curr;
    curr->data = 30;
    curr->next = NULL;
    display();




    return 0;
}
