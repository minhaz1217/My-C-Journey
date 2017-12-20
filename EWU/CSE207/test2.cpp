#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct Node{
    int data;
    Node *next;
};
Node *head,*tail,*curr,*temp,*temp2;

void addNode(){
    curr = (Node *) malloc(sizeof(Node));
    cout << "Enter: " ;
    cin >> curr->data;
    curr->next = NULL;
    if(head == NULL){
        head = curr;
        tail = head;
    }else{
        tail->next = curr;
        tail = curr;
    }
}
void displayList(){
    temp = head;
    while(temp!=NULL){
        cout << temp->data << " >> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverseList(Node *temp){
    if(temp->next == NULL){
        head = temp;
        return temp;
    }else{
        temp2 = reverseList(temp->next);
        temp2->next = temp;


    }
    //temp->next = NULL;
}


void removeDuplicates(){
    int a;
    Node *temp1,*temp2, *prev;
    temp1 = head;
    while(temp1 != NULL){
        prev = temp1;
        temp2 = temp1->next;
        a = temp1->data;
        while(temp2 != NULL){
            if(temp2->data == a){
                //remove
                Node *t = temp2;
                prev->next = temp2->next;
                temp2 = temp2->next;
                free(t);
            }else{
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}
int main(){
    head = NULL;
    displayList();
    int a = 5;
    while(a--){
        addNode();
    }
    displayList();
    reverseList(head);


    displayList();



    return 0;
}
