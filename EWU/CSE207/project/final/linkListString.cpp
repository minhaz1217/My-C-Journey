#include<iostream>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
// ls = link list string
struct ls_node{
    string lsStr;
    int line;
    ls_node *next;
}*lsHead, *lsTail, *lsTemp;
void createList(ls_node *&given, string str, int l){
    ls_node *curr, *tmp;

    curr = new ls_node;
    curr->lsStr = str;
    curr->line = l;
    curr->next = NULL;
    if(given == NULL){
        given = curr;
    }else{
        tmp = given;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = curr;
    }
}

void display(ls_node *given){
    ls_node *tmp;
    tmp = given;
    while(tmp != NULL){
        cout << tmp->line << " : " << tmp->lsStr;
        tmp = tmp->next;
    }
}
int search(ls_node *given, string srcString){
    ls_node *tmp;
    tmp = given;
    while(tmp!= NULL){
        if(tmp->lsStr == srcString){
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
void displayWithLines(ls_node *given){
    int counter = 1;
    ls_node *tmp;
    tmp = given;
    while(tmp != NULL){
        cout << counter++ << ": ";
        cout << tmp->lsStr;
        tmp = tmp->next;
    }
}
int isInteger(string s)
{
    int i;
    for(i=0;s[i];i++){
        if(isdigit(s[i]) == 0){
            if(s[i] == '.'){
                continue;
            }
            return 0;
        }
    }
    return 1;
}
void deleteIntegersFromList(ls_node *&given){
    ls_node *prev, *curr;
    prev = given;
    curr = given->next;
    while(prev != NULL){
        if(isInteger(curr->lsStr) == 1){
            ls_node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(temp);
        }
        prev = curr;
        curr = prev->next;
        if(curr == NULL){
            break;
        }
    }
}
