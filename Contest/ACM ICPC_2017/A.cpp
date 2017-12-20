# include <iostream>
# include <cstdio>
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *next, *prev;
};
node *head,*tail;

void addToLast(char c){
    node *curr;
    curr = new node;
    curr->data = c;
    curr->next = NULL;
    curr->prev = NULL;

    if(head == NULL){
        head = curr;
        tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail
        tail = curr;
    }
}


void delNode(node *tree){

}



int main(){
    string str;
    int tc, a,b,q;
    char c;

    cin >> tc;
    while(tc--){
        cin >> str;
        cin >> q;
        while(q--){
            cin >> a;
            if(a==2){
                str2 = str;

                //something something
            }else{
                cin >> b >> c;
            }
        }
    }

    cin >> str;


    return 0;
}
