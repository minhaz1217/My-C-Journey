/*
4.26 (Calculating the Value of PI) Calculate the value of PI from the infinite series
PI = 4 - 4/3 + 4/5 - 4/7
Print a table that shows the value of PI approximated by one term of this series, by two terms, by
three terms, and so on. How many terms of this series do you have to use before you first get 3.14?
3.141? 3.1415? 3.14159?
*/
#include<stdio.h>
main(){
    int i, flag= 1,steps = 1;
    double total = 4;
    for(i=3;i<310;i+=2){
        if(flag == 1){
            total -= (double)4/i;
            flag = 2;
        }else{
            total += (double)4/i;
            flag = 1;
        }
        printf("Term %d , PI: %1.2lf\n", steps, total);
        steps++;
    }

}
//ans is 151 terms
