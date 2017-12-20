/*
4.11 (Find the Smallest) Write a program that finds the smallest of several integers. Assume that
the first value read specifies the number of values remaining.
*/
#include<stdio.h>
main(){
    int a, i,num, small = 999999;
    printf("Enter how many numbers you want to input: ");
    scanf("%d", &a);
    for(i=0;i<a;i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num < small){
            small = num;
        }
    }
    printf("The smallest number you've entered is: %d", small);
}
