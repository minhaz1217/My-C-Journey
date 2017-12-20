#include <bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *next;
};
struct node *t,*head,*p,*o;

void   push(int n){
t=new node;
t->data=n;
t->next=NULL;
if(head==NULL){
head=t;
}
else{
p=head;
head=t;
}
}
int x;
int pop(){
o=head;
head=head->next;
x=o->data;
free(o);
return x;
}
void display(){
struct node *ptr;
ptr=t;
while(ptr!=NULL){
    cout<<ptr->data;
    ptr=ptr->next;
}
}
int main(){
    for( ; ; ){
int w,g,z,b,a;
cout<<"1.push stack "<<endl<<"2.print stack "<<endl<<"3.pop stack"<<endl<<"4.convert decimal"<<endl;

cout<<"enter choice"<<endl;

cin>>w;

if(w==1){
cout<<"how many numbers?"<<endl;
cin>>z;
for(int i=1;i<=z;i++){
    cout<<"enter numbers"<<endl;
        cin>>g;
push( g);
}
}

else if(w==2){
for(int i=1;i<=z;i++){
display();
//pop();
}
}
else if(w=3){
    for(int i=1;i<=z;i++){
        cout<<pop();
    }
}


else if(w==4){
    cout<<"enter the number"<<endl;
    cin>>b;
    while(b>0){
        a=b%2;
        b=b/2;
        push(a);
    }
    o=head;
    cout<<"resultant binary numb"<<endl;
    while(true){
    if(head!=NULL){
        cout<<pop()<<endl;
    }
    else break;}

}
    }
}


