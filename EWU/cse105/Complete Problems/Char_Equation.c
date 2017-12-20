#include<stdio.h>
main(){
    int num1, num2, result;
    char sign;
    num1 =0; num2=0;
    scanf("%d %c %d", &num1, &sign, &num2);
    switch(sign){
        case '+':
        result = num1 + num2;
        break;

        case '-':
        result = num1 - num2;
        break;

        case '/':
        result = num1 / num2;
        break;

        case '*':
        result = num1 * num2;
        break;
        case '%':
        result = num1 % num2;
        break;
        default:
        result = num1 + num2;
    }
    printf("%d %c %d = %d",num1, sign, num2, result );
}
