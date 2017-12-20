#include<stdio.h>
main(){
    int a,b;
    a = 5;
    b= 6;
    printf("The Variables before the switch\nNumber 1 = %d\nNumber 2 = %d\n", a, b);

    a= a+b;
    b= a-b;
    a= a-b;

    printf("The Variables after the switch\nNumber 1 = %d\nNumber 2 = %d\n", a, b);
}
