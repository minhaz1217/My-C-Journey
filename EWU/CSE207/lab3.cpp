#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *next;
};
struct Stack{
    int count;
    Node *head;
};
Stack st;
Node *tail, *curr, *prev,*temp;

void addToStack(){
    curr = new Node;
    cout <<"Enter data(only chars): ";
    cin >> curr->data;
    if(st.head == NULL){
        st.head = curr;
        curr->next = NULL;
    }else{
        curr->next = st.head;
        st.head = curr;
    }
    st.count++;
}
void push(char dat){
    curr = new Node;
    curr->data = dat;
    if(st.head == NULL){
        st.head = curr;
        curr->next = NULL;
    }else{
        curr->next = st.head;
        st.head = curr;
    }
    st.count++;
}

char pop(){
    if(st.count != 0){
        char temp = st.head->data;
        Node *freeVar;
        freeVar = st.head;
        st.head = freeVar->next;
        free(freeVar);
        st.count--;
        return temp;
    }else{
        //st.count--;
        return 0;
    }
}
void parseUnmatchedParenthesis(){
    string str;
    int flag = 1,i;
    st.count =0;
    st.head = NULL;
    cin.ignore();
    cout << "Enter the Line: ";
    getline(cin, str);
    flag = 1;
    for(i=0;str[i];i++){
        if(str[i] == '('){
            push(str[i]);
        }else if(str[i] == ')'){
            if(pop() != '('){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        cout << "Closing Parentheses not matched." << endl;
    }else if(st.count != 0){
        cout << "Opening parentheses not end." << endl;
    }else{
        cout << "Everything Seems to be in order." << endl;
    }
}
char giveHeadData(){
    if(st.head != NULL){
        return st.head->data;
    }else{
        return -1;
    }
}
void checkFullParenthesis(){
    string str;
    char cTemp;
    int flag = 1,i,popCounter = 0,alreadyChecked = 0;
    st.count =0;
    st.head = NULL;
    cin.ignore();
    cout << "Enter the Line: ";
    getline(cin, str);
    flag = 1;
    for(i=0;str[i];i++){
        if(str[i] == '('){
            push(str[i]);
        }else if(str[i] == ')'){
            cTemp = pop();
            alreadyChecked = alreadyChecked == 0? 0: alreadyChecked--;
            if(cTemp != '('){
                flag = 0;
                break;
            }
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){

            alreadyChecked++;
            if(giveHeadData() != '(' || alreadyChecked >1){
                flag = 0;
                break;
            }

        }
    }
    if(flag == 0){
        cout << "Closing Parentheses not matched." << endl;
    }else if(st.count != 0){
        cout << "Opening parentheses not end." << endl;
    }else{
        cout << "Everything Seems to be in order." << endl;
    }
}
void display(){
    cout << endl;
    temp = st.head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl<<endl;
}
void reverseData(){
    int num;
    st.count = 0;
    st.head = NULL;
    cout << "Ender the number: ";
    cin >> num;
    while(num !=0 ){
        push(num%2 + '0');
        num=num/2;
    }
    display();
}


void displayNumber(){
    cout << endl;
    temp = st.head;
    while(temp != NULL){
        cout << (temp->data - '0') << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl<<endl;
}
void menu(){
    int ch;
    cout << "1. Display" << endl;
    cout << "2. Push" << endl;
    cout << "3. Pop" << endl;
    cout << "4. Parsing Unmatched Parenthesis" << endl;
    cout << "5. Reverse Data"  << endl;
    cout << "6. Check full parenthesis." << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    switch(ch){
    case 1:
        display();
        break;
    case 2:
        addToStack();
        break;
    case 3:
        cout << pop() << endl;
        break;
    case 4:
        parseUnmatchedParenthesis();
        break;
    case 5:
        reverseData();
        break;
    case 6:
        checkFullParenthesis();
        break;
    case 0:
        exit(0);
        cout << endl << endl << "Exited" << endl << endl;
        break;
    default:
        menu();
    }
}
int main(){
    st.count = 0;
    st.head = NULL;
    int a = 3,num;
    while(1){
        menu();
    }
    return 0;
}
