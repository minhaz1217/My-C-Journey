#include<iostream>
#include<cstdlib>
using namespace std;
#define check(a) cout<<a<< endl;

class LinkList{
public:
    LinkList *prev, *next;
    int data,counter;
    LinkList(){
        counter =0;
    }
};

int main(){
    LinkList *start,*current,*temp;
    start = (LinkList *) malloc(sizeof(LinkList));
    current = start;
    current->prev = NULL;
    char choice;
    for(;;){
        cout <<"Enter data to store: ";
        cin >> current->data;
        cout <<  "Do you want another?(y/n): ";
        cin >> choice;
        if(choice == 'y'){
            current->next = (LinkList *) malloc(sizeof(LinkList));
            temp = current;
            current = current -> next;
            current->prev = temp;
        }else{
            current -> next = NULL;
            break;
        }

    }
    current = start;
    while(1){
        cout << "Prev: " << current ->prev << endl;
        cout << "ID: " << current ->data << endl;;
        cout << "Next: " << current ->next << endl;
        if(current ->next == NULL){
            break;
        }else{
        current = current -> next;
        }
        }
	return 0;
}
