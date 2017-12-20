#include<stdio.h>
main(){
    int number, i, result;
    number = 123;
    result = 0;
    while(number>0){
        result = result * 10 + (number%10)+1;
        number = number/10;
    }
    number = result;
    while(number>0){
        printf("%d\n", number%10);
        number = number/10;
    }
}
