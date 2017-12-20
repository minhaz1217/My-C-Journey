/*
4.16 (Triangle-Printing Program) Write a program that prints the following patterns separately,
one below the other. Use for loops to generate the patterns. All asterisks (*) should be printed by a
single printf statement of the form printf( "%s", "*" ); (this causes the asterisks to print side by
side). [Hint: The last two patterns require that each line begin with an appropriate number of blanks.]

(A) (B) (C) (D)
* ********** ********** *
** ********* ********* **
*** ******** ******** ***
**** ******* ******* ****
***** ****** ****** *****
****** ***** ***** ******
******* **** **** *******
******** *** *** ********
********* ** ** *********
********** * * **********
*/
#include<stdio.h>
main(){
    int i,j,k;

    for(i=0;i<=10;i++){
        for(j=0;j<=i;j++){
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=10;i>=0;i--){
        for(j=0;j<=i;j++){
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=10;i>=0;i--){
        for(j=0;j<=10-i;j++){
            printf(" ");
        }
        for(k=0;k<=i;k++){
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0;i<=10;i++){
        for(j=0;j<=10-i;j++){
            printf(" ");
        }
        for(k=0;k<=i;k++){
            printf("%s", "*");
        }
        printf("\n");
    }
}
