#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

struct Node{
    int data;
    Node *next;
};
Node *head,*tail,*curr,*temp;
Node *front, *rear;

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


void enqueue(int d){
    curr = new Node;
    curr->data = d;
    curr->next = NULL;
    if(front == NULL){
        front = curr;
        rear = curr;
    }else{
        rear->next = curr;
        rear = curr;
    }
}
void dequeue(){
    Node *freeTemp;
    freeTemp = front;
    front = freeTemp->next;
    free(freeTemp);

}
int getfront(){
    return front->data;
}

void displayQueue(){
    temp = front;
    while(temp!=NULL){
        cout << temp->data << " >> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void displayTargetedQueue(Node *s){
    temp = s;
    while(temp!=NULL){
        cout << temp->data << " >> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void copyQueue(Node *source, Node **destination){
    //displayTargetedQueue(source);
    *&*destination = NULL;
    Node *desRear;
    temp = source;
    while(temp!= NULL){
        curr = new Node;
        curr->data = temp->data;
        curr->next = NULL;
        if(*&*destination == NULL){
            *&*destination = curr;
            desRear = curr;
        }else{
            desRear->next = curr;
            desRear = curr;
        }
        temp = temp->next;
    }
   // msg(destination, destination->data)
    //displayTargetedQueue(destination);
}
void queueConcat(){

}

void checking(Node **d){
    cout << &*d << endl;
    curr = new Node;
    curr ->data = 10;
    *&*d = curr;
    cout << &*d << endl;
}

int main(){
    Node *d,*s;
    front = NULL;
    s = NULL;
    d = NULL;
    int a=3;
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    cout << "After Enqueue" << endl;
    displayQueue();
    dequeue();
    cout << "After Dequeue" << endl;
    displayQueue();
    cout << "SOURCE" << endl;
    displayQueue();
    cout << "After copying." << endl;
    copyQueue(front, &d);
    displayTargetedQueue(d);




    return 0;
}
