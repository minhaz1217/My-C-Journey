/*
4.33 (Roman-Numeral Equivalent of Decimal Values) Write a program that prints a table of all
the Roman numeral equivalents of the decimal numbers in the range 1 to 100.
*/
#include<stdio.h>
main(){
    int i,j;
    for(i=1;i<=3;i++){
            printf("%d = ", i);
        if(i<=3){
            for(j=1;j<=i;j++){
                printf("I");
            }
        }
        printf("\n");
    }
}
