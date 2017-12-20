#include<stdio.h>
main(){
    int number, i, result;
    number = 123;
    result = 0;
    while(number>0){
        result =number%10;
        printf("%d\n", result);
        number = number/10;
    }
}
