#include<stdio.h>
main(){
    int num;
    printf("Enter A Number: ");
    scanf("%d", &num);
    if(num%2!=0)
        printf("ODD");
    else
        printf("EVEN");
}
