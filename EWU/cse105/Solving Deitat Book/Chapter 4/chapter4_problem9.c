/*
4.9 (Sum a Sequence of Integers) Write a program that sums a sequence of integers. Assume that
the first integer read with scanf specifies the number of values remaining to be entered. Your program
should read only one value each time scanf is executed. A typical input sequence might be
5 100 200 300 400 500
where the 5 indicates that the subsequent five values are to be summed.
*/

#include<stdio.h>
main(){
    int a, sum = 0,i,num = 0;
    printf("Enter how many you want to input: ");
    scanf("%d", &a);
    for(i=0;i<a;i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        sum += num;
    }
    printf("The sum of the numbers you inputed is: %d", sum);
}
