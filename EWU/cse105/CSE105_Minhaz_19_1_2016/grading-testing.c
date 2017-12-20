#include<stdio.h>
main(){
    int num, res;
    printf("Enter Your Number: ");
    scanf("%d", &num);
    if(num >= 80 && num <=100)
        printf("A");
    else if(num >=70 && num <80)
        printf("B");
    else if(num >= 60 && num <70)
        printf("C");
    else
        printf("F");
}
