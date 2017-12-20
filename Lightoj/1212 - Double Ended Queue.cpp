#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

struct node{
    int data;
    node *next;

};
node *curr;
struct Queue{
    int qsize;
    node *head,*tail;
};
Queue q;
void pushLeft(int d){
    curr = new node;
    curr->next = NULL;
    curr->data = d;
    if(q.head == NULL){
        q.head = curr;
        q.tail = curr;
    }else{
        curr->next = q.head;
        q.head = curr;
    }
    q.qsize++;
}
void pushRight(int d){
    curr = new node;
    curr->next = NULL;
    curr->data = d;
    if(q.head == NULL){
        q.head = curr;
        q.tail = curr;
    }else{
        q.tail->next = curr;
        q.tail = curr;
    }
    q.qsize++;
}
int popLeft(){
    node *temp = q.head;
    int tmp = q.head->data;
    q.head = q.head->next;
    delete(temp);
    q.qsize--;
    return tmp;
}
int popRight(){
    node *temp,*prev;
    int tmp;
    if(q.qsize >= 2){
        prev = q.head;
        temp = q.head->next;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tmp = temp->data;
        delete(temp);
    }else{
        temp = q.head;
        tmp = q.head->data;
        q.head = temp->next;
        delete(temp);
    }
    q.qsize--;
    return tmp;
}

void emptyQ(){
    node *tmp = q.head;
    q.head = NULL;
    q.tail = NULL;
    while(tmp!=NULL){
        node *t = tmp;
        tmp = tmp->next;
        delete(t);
    }
    q.qsize = 0;

}

int main(){
    int tc,a,qq,s,caseCounter = 1;
    string str;
    cin >> tc;
    while(tc--){
        cin >> s >> qq;
        q.head =NULL;
        q.qsize = 0;
        cout << "Case "<< caseCounter++ << ": " << endl;

        while(qq--){
            cin >> str;
            if(str == "pushLeft"){
                cin  >> a;
                if(q.qsize < s){
                    pushLeft(a);
                    cout << "Pushed in left: " << a << endl;
                }else{
                    cout << "The queue is full" << endl;
                }
            }else if(str == "pushRight"){
                cin  >> a;
                if(q.qsize < s){
                    pushRight(a);
                    cout << "Pushed in right: " << a << endl;
                }else{
                    cout << "The queue is full" << endl;
                }
            }else if(str == "popLeft"){
                if(q.qsize > 0){
                    cout << "Popped from left: " << popLeft() << endl;
                }else{
                    cout << "The queue is empty" << endl;
                }
            }else if(str == "popRight"){
                if(q.qsize > 0){
                    cout << "Popped from right: " << popRight() << endl;
                }else{
                    cout << "The queue is empty" << endl;
                }
            }
        }
        emptyQ();
    }



    return 0;
}
