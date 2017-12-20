/*
4.18 (Bar Chart Printing Program) One interesting application of computers is drawing graphs
and bar charts (sometimes called “histograms”). Write a program that reads five numbers (each between
1 and 30). For each number read, your program should print a line containing that number
of adjacent asterisks. For example, if your program reads the number seven, it should print *******.
*/

#include<stdio.h>
main(){
    int i, num, j;
    for(i=0;i<5;i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        for(j=1;j<=num;j++){
            printf("*");
        }
        printf("\n");
    }
}
