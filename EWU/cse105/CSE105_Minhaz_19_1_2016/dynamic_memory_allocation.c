#include<stdio.h>
#include<stdlib.h>
main(){
    struct info{
        char name[20];
        int id;
        float cgpa;
        struct info *next;
    };
    struct info *starting, *current, ran;
    char response;
    starting =malloc(sizeof(struct info));
    current = starting;
    for(;;){
        printf("Enter A Name: ");
        scanf("%s", &current -> name);
        printf("Enter Id: ");
        scanf("%d", &current -> id);
        printf("Enter CGPA: ");
        scanf("%f", &current->cgpa);
        printf("\nDo you want to enter another INFO?(y/n): ");
        scanf("%s", &response);
        if(response == 'y' || response == 'Y'){
            current -> next = malloc(sizeof(struct info));
            current = current -> next;
        }else if(response == 'n' || response == 'N'){
            current -> next = NULL;
            break;
        }
    }
    current = starting;
    for(;;){
        printf("Name: %s\n Id: %d\n CGPA: %f\n", current->name, current->id, current->cgpa);
        if(current-> next == NULL){
            break;
        }
        current = current -> next;


    }


}
