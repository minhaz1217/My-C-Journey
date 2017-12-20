#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};

struct Stack{
    node *head = NULL;
    int stackSize = 0;
};

struct Queue{
    node *head = NULL;
    node *tail = NULL;
    int queueSize = 0;
};

node *curr, *prev;

void push(Stack &st, int a){
    curr = new node;
    curr->data = a;
    curr->next = NULL;

    if(st.head == NULL){
        st.head = curr;
    }else{
        curr->next = st.head;
        st.head = curr;
    }
    st.stackSize++;
}
int pop(Stack &st){
    if(st.stackSize == 0){
        cout << "NO DATA IN STACK" << endl;
        return 0;
    }
    node *temp = st.head;
    int t = st.head->data;
    st.head = st.head->next;
    delete temp;
    st.stackSize--;

    return t;


}

void enqueue(Queue &qu, int a){
    curr = new node;
    curr->data = a;
    curr->next = NULL;

    if(qu.head == NULL){
        qu.head = curr;
        qu.tail = curr;
    }else{
        qu.tail->next = curr;
        qu.tail = curr;
    }
    qu.queueSize++;
}
int dequeue(Queue &qu){
    if(qu.queueSize == 0){
        cout << "NO DATA IN QUEUE" << endl;
        return 0;
    }
    node *temp = qu.head;
    int t = qu.head->data;
    qu.head = qu.head->next;
    delete temp;
    return t;
}

void display(Stack &st){
    curr = st.head;
    while(curr != NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}
void display(Queue &qu){
    curr = qu.head;
    while(curr != NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}

Queue createQueueFromStack(Stack &s){
    Queue qq;
    node *cur;
    cur = s.head;
    while(cur != NULL){
        enqueue(qq, cur->data);
        cur = cur->next;
    }
    return qq;
}


int main(){
    Stack s1;
    Queue q1;
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    cout << "Displaying the stack" << endl;
    display(s1);
    /*
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    cout << "Displaying the Queue" << endl;
    display(q1);
    */
    //cout << "ST SIZE" << s1.stackSize << endl;

    q1 = createQueueFromStack(s1);
    cout << "Displaying the new queue" << endl;
    display(q1);
    cout << q1.queueSize << endl;

    return 0;
}
