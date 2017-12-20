#include<stdio.h>
main(){
    int number, i, result;
    number = 123456789;
    result = 0;
    for(number=number;number>0;number = number/10){
        result = result*10 + (number%10);
    }
    printf("%d\n",result);
}
