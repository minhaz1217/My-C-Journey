/*
4.31 (Diamond-Printing Program) Write a program that prints the following diamond shape.
You may use printf statements that print either a single asterisk (*) or a single blank. Maximize
your use of repetition (with nested for statements) and minimize the number of printf statements.
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
#include<stdio.h>
main(){
    int a=9, i,j,space,k;
    space = a;
    for(i=1;i<=a;i+=2){
        for(j=1;j<=space/2;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("*");
        }
        printf("\n");
        space-=2;
    }
    space = 1;
    for(i=a-2;i>=1;i-=2){
        for(j=1;j<=space;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("*");
        }
        printf("\n");
        space++;
    }
}
