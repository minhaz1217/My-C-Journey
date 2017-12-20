/*
4.12 (Calculating the Sum of Even Integers) Write a program that calculates and prints the sum
of the even integers from 2 to 30.
*/
#include<stdio.h>
main(){
    int sum = 0, i;
    for(i=2;i<=30;i +=2){
        sum += i;
    }
    printf("The sum of the even integers from 2 to 30 is: %d", sum);
}
