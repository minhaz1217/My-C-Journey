#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct Node{
    int data;
    Node *next;
};
Node *head,*tail,*curr,*temp;

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
void sortLinkList(){
    Node *temp1,*temp2,*prev;
    temp1 = head;
    temp2 = temp1->next;
    prev = temp1;
    while(temp1 != NULL){
        temp2 = temp1->next;
        while(temp2 != NULL){
            if(temp1->data > temp2->data){
                if(prev!=head){
                    prev->next = temp2;
                }else{
                    head = temp2;
                }
                temp1->next = temp2->next;
                temp2->next = temp1;
                prev = temp2;

                cout << "Switched" << endl;
                temp2 = temp1->next;
            }else{
                temp2 = temp2->next;
            }
        }
        prev = temp1;
        temp1 = temp1->next;
    }
}


void sorting(){
    Node *ii,*jj,*previ, *prevj,*temp1,*temp2;
    ii = head;
    previ = head;

    while(ii != NULL){
        prevj = ii;
        jj = ii->next;
        while(jj != NULL){
            if(ii->data > jj->data){
                if(previ != head){
                    previ->next = jj;
                    prevj->next = ii;
                    temp1 = ii->next;
                    ii->next = jj->next;
                    jj->next = temp1;
                }else{
                    head = jj;
                    ii->next = jj->next;
                    jj->next = ii;
                    prevj = jj;
                }
                temp1 = ii;
                ii = jj;
                jj = ii;

            }
            prevj = jj;
            jj = jj->next;
            displayList();
        }
        cout << "jj: " ;
        displayList();
        previ = ii;
        ii = ii->next;
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
    sorting();
    displayList();



    return 0;
}
