#include<iostream>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
// qs = queue of string
struct qs_node{
    string qsStr;
    int line;
    int error;
    qs_node *next;
}*qsHead, *qsTail, *qsTemp;
struct qs_queue{
    qs_node *head = NULL;
    int size = 0;
};
void enqueue(qs_queue &given, string st, int l, int err){
    qs_node *curr,*tmp;
    curr = new qs_node;
    curr->qsStr = st;
    curr->line = l;
    curr->error = err;
    curr->next = NULL;
    if(given.head == NULL){
        given.head = curr;
    }else{
        tmp = given.head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = curr;
    }
    given.size++;
}
string dequeue(qs_queue &given){
    if(given.size!= 0){
        qs_node *tmp = given.head;
        string st_temp = tmp->qsStr;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return st_temp;
    }else{
        return "-1";
    }
}
qs_node dequeueNode(qs_queue &given){
    if(given.size!= 0){
        qs_node *tmp = given.head;
        qs_node temp;
        temp.qsStr = tmp->qsStr;
        temp.line = tmp->line;
        temp.error = tmp->error;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return temp;
    }else{
        return qs_node();
    }
}
string front(qs_queue given){
    if(given.size!= 0){
        return given.head->qsStr;
    }else{
        return 0;
    }
}
qs_node frontNode(qs_queue given){
    if(given.size!= 0){
        return qs_node{given.head->qsStr, given.head->line, given.head->error};
    }else{
        return qs_node();
    }
}
void display(qs_queue given){
    qs_node *tmp = given.head;
    while(tmp != NULL){
        cout << tmp->qsStr << " At line: " << tmp->line << " Error Code: " << tmp->error << " " << endl;
        tmp = tmp->next;
    }
}

