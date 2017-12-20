#include<iostream>
using namespace std;
class link{
public:
    int data;
    link *next;
};
class Linklist{
    link *first;
public:
    Linklist(){
        first = NULL;
    }
    void addItem(int d){
        link *temp;
        temp = new link;
        temp -> data = d;
        temp -> next = first;
        first = temp;
    }
    void display(){
        link *current;
        current = first;
        while(current != NULL){
            cout << current->data << endl;
            current = current->next;
        }
    }
};
int main(){
    Linklist ll;
    ll.addItem(10);
    ll.addItem(50);
    ll.addItem(5);
    ll.display();
	return 0;
}
