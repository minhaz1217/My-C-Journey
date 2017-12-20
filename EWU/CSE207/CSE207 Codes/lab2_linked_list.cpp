#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
int nodeSize = 0;
Node *curr, *head, *tail;

void insertNodeAtEnd(){
    curr = (Node *) malloc(sizeof(Node));
    cout << "Insert Data: ";
    cin >> curr->data;
    curr->next = NULL;
    if(head == NULL){
        head = curr;
        tail = curr;
    }else{
        tail->next = curr;
        tail = curr;
    }
    nodeSize++;
}

void insertNodeAtBegining(){
    curr = (Node *) malloc(sizeof(Node));
    cout << "Insert Data: ";
    cin >> curr->data;
    curr->next = NULL;
    if(head == NULL){
        head = curr;
    }else{
        curr->next = head;
        head = curr;
    }
    nodeSize++;
}
void insertNodeAtAnyPosition(){
    int pos,i;
    cout << "Input position: ";
    cin >> pos;
    curr = head;
    if(pos >=1 && pos<= nodeSize+1){
        if(pos == 1){
            insertNodeAtBegining();
        }else if(pos == nodeSize+1){
            insertNodeAtEnd();
        }else{
            for(i=1;i<pos-1;i++){
                curr = curr->next;
            }
            Node *newCurr;
            newCurr = (Node *) malloc(sizeof(Node));
            cout << "Insert Data: ";
            cin >> newCurr->data;
            newCurr->next = curr->next;
            curr->next = newCurr;
            nodeSize++;
        }
    }else{
        cout << "Invalid Position." << endl;
    }
}
void display(){
    curr = head;
    cout << endl;
    while(curr!=NULL){
        cout << curr->data << " --> ";
        curr = curr->next;
    }
    cout << "NULL" << endl << endl;
}
void deleteNodeFromBegining(){
    if(nodeSize -1 == -1){
        cout << "The Node is empty." << endl;
        return;
    }
    Node *temp;
    temp = head;
    head = temp->next;
    free(temp);
    nodeSize--;
}
void deleteNodeFromLast(){
    if(nodeSize -1 == -1){
        cout << "The Node is empty." << endl;
        return;
    }
    Node *temp,*prev;
    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    nodeSize--;
}
void deleteNodeFromAnyPosition(){
    if(nodeSize -1 == -1){
        cout << "The Node is empty." << endl;
        return;
    }
    int pos,i;
    cout << "Input position to delete the list.";
    cin >> pos;
    if(pos>=1 && pos<= nodeSize){
        if(pos == 1){
            deleteNodeFromBegining();
        }else if(pos == nodeSize){
            deleteNodeFromLast();
        }else{
            Node *temp;
            temp = head;
            for(i=1;i<pos;i++){
                curr = temp;
                temp = temp->next;
            }
            curr->next = temp->next;
            free(temp);
            nodeSize--;
        }
    }else{
        cout << "INVALID POSITION ENTERED." << endl;
    }
}
void reverseTheList(){
    if(nodeSize -1 == -1){
        cout << "The Node is empty." << endl;
        return;
    }
    Node *temp,*prev;
    curr = head->next;
    temp = head;
    temp->next = NULL;
    while(prev!=NULL){
        prev = curr->next;
        curr->next = temp;
        temp = curr;
        curr = prev;
    }
    head = temp;
}
void menu(){
    int choice;
    //system("cls");

    cout << "1. Display" << endl;
    cout << "2. Insert new node" << endl;
    cout << "3. Insert node at beginning" << endl;
    cout << "4. Insert node at any position" << endl;
    cout << "5. Delete Node from last position" << endl;
    cout << "6. Delete Node from beginning" << endl;
    cout << "7. Delete Node from any position" << endl;
    cout << "8. Reverse" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;
    switch(choice){
        case 1:
            display();
            break;
        case 2:
            insertNodeAtEnd();
            break;
        case 3:
            insertNodeAtBegining();
            break;
        case 4:
            insertNodeAtAnyPosition();
            break;
        case 5:
            deleteNodeFromLast();
            break;
        case 6:
            deleteNodeFromBegining();
            break;
        case 7:
            deleteNodeFromAnyPosition();
            break;
        case 8:
            reverseTheList();
            break;
        case 0:
            exit(0);

        default:
            menu();
    }
}

int main(){
    int i;
    head = NULL;

/*
    for(i=1;i<=5;i++){
        insertNodeAtEnd();
    }
    display();
    reverseTheList();
    display();
*/
    while(1){menu();}

    return 0;
}
