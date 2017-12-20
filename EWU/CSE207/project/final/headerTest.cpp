#include<bits/stdc++.h>
#include "linkListString.cpp"
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    ls_node *head;
    head = NULL;
    createList(head, "HI ");
    createList(head, "HI ");
    createList(head, "HI ");
    display(head);
    return 0;
}
