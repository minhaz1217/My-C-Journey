#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
}*node,*temp;

struct Head
{
    int count;
    struct Node *p;
}*head;

void creat_head()
{
    head=(struct Head*)malloc(sizeof(struct Head));
    head->count=0;
    head->p=NULL;
}

void creat_node()
{
    node=(struct Node*)malloc(sizeof(struct Node));
    printf("enter the values=");
    scanf("%d",&node->data);
    node->next=NULL;
}
void insert_1st()
{
    creat_node();
    node->next=head->p;
    head->p=node;
    // head->count++;
}
void display()
{
    temp=head->p;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void insert_last()
{
    temp=head->p;
    while(temp->next!=NULL)
        temp=temp->next;
    creat_node();
    temp->next=node;
    head->count++;
}
void insert_anywhere()
{
    int n,data_value;
    scanf("%d",&data_value);
    scanf("%d",&n);
    temp=(struct node*)malloc(sizeof(struct node));
    p=head;
    while(p->link!=NULL && p->data!=n)
    {
       p->link;
    }
    if( p->link==n)
    {

    }
    else
        printf("data not found");
    creat_node();

}

void delete_1st()
{
    int count=0;
    if(count>0)
    {
        temp=head->p;
        head->p=temp->next;
        head->count--;
        free(temp);
    }
    else
        printf("there have no data");

}
void delete_last()
{
    int c;
    temp=head->p;
    c=1;
    while(c<=head->count-1)
    {
        temp=temp->next;
        c++;
    }
    free(temp->next);
    temp->next=NULL;
}


int main()
{
    creat_head();
    insert_1st();
    insert_1st();
    insert_1st();
    display();
    insert_last();
    display();
    insert_anywhere();
    display();
    delete_1st();
    display();



}
