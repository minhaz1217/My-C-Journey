#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct node{
    int data;
    node *next;
};

struct Queue{
    node *head = NULL;
    node *tail = NULL;
    int queueSize = 0;
};

node *curr;
void enqueue(Queue &q, int n){
    curr = new node;
    curr->data = n;
    curr->next = NULL;
    if(q.head == NULL){
        q.head = curr;
        q.tail = curr;
    }else{
        q.tail->next = curr;
        q.tail = curr;
    }
    q.queueSize++;
}
int dequeue(Queue &q){
    node *temp = q.head;
    q.head = q.head->next;
    int t = temp->data;
    free(temp);
    q.queueSize--;
    return t;
}
void display(Queue &q){
    curr = q.head;
    while(curr!=NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}



int main(){
    Queue qq;
    enqueue(qq, 5);
    enqueue(qq, 50);
    enqueue(qq, 500);
    enqueue(qq, 5000);
    enqueue(qq, 50000);
    display(qq);
    msg("SIZE", qq.queueSize)
    cout << dequeue(qq) << endl;

    msg("SIZE", qq.queueSize)
    return 0;
}
