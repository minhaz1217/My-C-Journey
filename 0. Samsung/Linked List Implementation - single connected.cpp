#include<iostream>
using namespace std;
#define msg(a) cout << a << endl;
class node{
    public:
    int val;
    node *next, *prev;


    node(){
        val = 0;
        next = NULL;
        prev = NULL;
    }
};
class LinkedList{
    public:
    node *head, *tail;
    LinkedList(){
        head = NULL;
        tail = NULL;

    }

    void pushBack(int val){
        node *curr = new node();
        curr->val = val;
        if(head == NULL){
            head = curr;
            tail = curr;
        }else{
            tail->next = curr;
            tail = curr;
        }
    }
    void pushFront(int val){
        node *curr = new node();
        curr->val = val;
        curr->next = head;
        if(head == NULL){
            head = curr;
            tail = curr;
        }else{
            head = curr;
        }
    }
    void popBack(){
        if(head!= NULL)
        if(head == tail){// only has one block
            cout << "FREEING " << head->val << endl;
            free(head);
            head = tail = NULL;
        }else{
            node *curr = head, *temp = tail;
            while(curr->next->next != NULL){
                curr = curr->next;
            }
            tail = curr;
            tail->next = NULL;
            cout << "FREEING 2 " << temp->val << " NOW " << tail->val << endl;
            free(temp);
        }
    }
    void popFront(){
        node *temp = head;
        if(head!= NULL){
            head = head->next;
            free(temp);
        }
    }
    void print(){
        node *curr = head;
        while(curr != NULL){
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(3);
    ll.print();
    ll.popBack();
    ll.print();
    ll.popBack();
    ll.print();
    ll.popBack();
    ll.print();
    ll.popBack();
    ll.print();
    ll.popBack();
    ll.print();
    cout << "HI" <<endl;
    return 0;
}
