#include<stdio.h>
main(){
    int number, i, result;
    number = 21;
    result = 0;
    while(number>0){
        result = result*10 + (number%10);
        number = number/10;
    }
    printf("%d\n",result);
}
