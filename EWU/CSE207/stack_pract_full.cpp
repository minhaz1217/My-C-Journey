#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct node{
    int data;
    node *next;

};
node *head,*tail,*curr,*prev;
struct Stack{
    node *head = NULL;
    int stackSize=0;
};
//Stack st;
void push(Stack &st, int n){

    curr = new node;
    curr->data = n;
    curr->next = NULL;
    if(st.head == NULL){
        st.head = curr;
    }else{
        curr->next = st.head;
        st.head = curr;
    }
    st.stackSize++;
}
int top(Stack &st){
    return st.head->data;
}
int pop(Stack &st){
    node *temp = st.head;
    st.head = st.head->next;
    int t = temp->data;
    delete temp;
    st.stackSize--;
    return t;
}
void display(Stack &st){
    curr = st.head;
    while(curr!=NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }
}
/*
void push(Stack *s, int n){
    if(s->head == NULL){
        curr = new node;
        curr->data = n;
        curr->next = NULL;
        s->
    }else{
        push(s->next, n);
    }
}
\*/


int main(){
    head = NULL;
    Stack stt;
    stt.head = NULL;

    push(stt, 5);
    push(stt, 10);
    push(stt, 15);
    push(stt, 20);
    push(stt, 25);
    display(stt);
    cout << pop(stt) << endl;
    cout << endl;
    display(stt);
    return 0;
}
