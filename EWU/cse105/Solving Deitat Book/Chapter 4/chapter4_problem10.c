/*
4.10 (Average a Sequence of Integers) Write a program that calculates and prints the average of
several integers. Assume the last value read with scanf is the sentinel 9999. A typical input sequence
might be
10 8 11 7 9 9999
indicating that the average of all the values preceding 9999 is to be calculated.
*/
#include<stdio.h>
main(){
    int num, sum=0, count = 0, i;
    double avg = 0;
    for(;;){
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num == 9999){
            break;
        }else{
            sum += num;
            count++;
        }
    }
    avg = sum/count;
    printf("The average of the numbers you entered is: %lf", avg);
}
