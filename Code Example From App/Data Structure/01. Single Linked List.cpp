#include<stdio.h>
#include<malloc.h>
struct node{
    int info;
    struct node *link;
}*start;
int main(){
    int choice, n, m ,l position,i;
    start = NULL;
    while(1){
        printf("1. Create List\n");
        printf("2. Add at beginning\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Count\n");
        printf("7. Reverse\n");
        printf("8. Search\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }



    return 0;
}
