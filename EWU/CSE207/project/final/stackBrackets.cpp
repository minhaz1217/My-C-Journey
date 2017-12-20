#include<bits/stdc++.h>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
//sc = stack character
struct sc_node{
    char ch;
    int line;
    sc_node *next;
};

struct sc_stack{
    sc_node *head = NULL;
    int size = 0;
};
void push(sc_stack &given, char c, int l){
    sc_node *curr;
    curr = new sc_node;
    curr->ch = c;
    curr->line = l;
    curr->next = NULL;
    if(given.head == NULL){
        given.head = curr;
    }else{
        curr->next = given.head;
        given.head = curr;
    }
    given.size++;
}
char pop(sc_stack &given){
    if(given.size!= 0){
        sc_node *tmp = given.head;
        char ch_temp = tmp->ch;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return ch_temp;
    }else{
        return 0;
    }
}
sc_node popNode(sc_stack &given){
    if(given.size!= 0){
        sc_node *tmp = given.head;
        sc_node temp;
        temp.ch = tmp->ch;
        temp.line = tmp->line;
        char ch_temp = tmp->ch;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return temp;
    }else{
        return sc_node();
    }
}
char top(sc_stack given){
    if(given.size!= 0){
        return given.head->ch;
    }else{
        return 0;
    }
}
sc_node topNode(sc_stack given){
    if(given.size!= 0){
        return sc_node{given.head->ch, given.head->line};
    }else{
        return sc_node();
    }
}
void display(sc_stack given){
    sc_node *tmp = given.head;
    while(tmp != NULL){
        printf("%c, %d\n", tmp->ch, tmp->line);
        tmp = tmp->next;
    }
}

/*
int main(){
    sc_stack ss;
    push(ss, 'a', 4);
    push(ss, 'b', 5);
    push(ss, 'c', 6);
    display(ss);

    cout << pop(ss) << endl;
    cout << pop(ss) << endl;
    cout << top(ss) << endl;
    cout << top(ss) << endl;
    cout << top(ss) << endl;


    sc_node myT = popNode(ss);
    cout << myT.ch << endl;
    myT = popNode(ss);
    cout << myT.ch << endl;
    myT = popNode(ss);
    cout << myT.ch << endl;
    myT = popNode(ss);
    cout << myT.ch << endl;


    sc_node myTt = topNode(ss);
    cout << myTt.ch << endl;
    cout << myTt.line << endl;

    return 0;
}
*/
