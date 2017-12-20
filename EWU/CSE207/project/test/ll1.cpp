#include<bits/stdc++.h>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct node{
    int data;
    node *n;
};
node *he;
void createList(node *&head, int d){


    if(head == NULL){
        head = new node;
        head->data = d;
        head ->n = NULL;
    }
}



int main(){
    he = NULL;
    createList(he, 22);
    c(he->data )

    return 0;
}
