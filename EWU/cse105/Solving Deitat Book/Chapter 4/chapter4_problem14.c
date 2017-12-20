/*
4.14 (Factorials) The factorial function is used frequently in probability problems. The factorial of
a positive integer n (written n! and pronounced “n factorial”) is equal to the product of the positive
integers from 1 to n. Write a program that evaluates the factorials of the integers from 1 to 5. Print the
results in tabular format. What difficulty might prevent you from calculating the factorial of 20?
*/
#include<stdio.h>
main(){
    int i, fact=1, j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            fact *= j;
        }
        printf("The Factorial of %d is: %d\n", i, fact);
        fact = 1;
    }
}
