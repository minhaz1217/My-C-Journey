#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
struct link{
int data;
link *next;
};
class Linklist{
private:
    link *first;
public:
    Linklist(){
        first = NULL;
    }
    void additem(int d){
        link *newlink = new link;
        newlink-> data = d;
        newlink -> next = first;
        first = newlink;
    }
    void display(){
        link *current = first;
        while(current !=NULL){
            cout << current -> data  << endl;
            current = current ->next;
        }
    }
    ~Linklist(){
        link *current = first,*next;
        while(1){
            cout << "Deleting " << current->data << endl;
            if(current->next == NULL){
                delete current;
                break;
            }
            next = current-> next;
            delete current;
            current = next;
        }

    }
};
int main(){
    Linklist li;
    li.additem(20);
    li.additem(10);
    li.additem(30);
    li.additem(100);
    li.display();


	return 0;
}
