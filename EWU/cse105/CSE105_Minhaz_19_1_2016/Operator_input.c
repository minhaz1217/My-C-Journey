#include<stdio.h>
main(){
    char input;
    int num1,num2,result;

    printf("Num1 Operator Num2 : ");
    scanf("%d %c %d", &num1, &input, &num2);
/*
    printf("Num2 : ");
    scanf("%d", &num2);


    printf("Operator: ");
    scanf("%c", &input);
*/
    if(input == '+'){
        result = num1+num2;
        printf("Addition: %d" , result);
    }
    else if(input == '-'){
        result = num1-num2;
        printf("Substraction: %d" , result);
    }
    else if(input == '*'){
        result = num1*num2;
        printf("Multiplication: %d" , result);
    }
    else if(input == '/'){
        result = num1/num2;
        printf("Division: %d" , result);
    }
    else if(input == '%'){
        result = num1%num2;
        printf("Modulus %d" , result);
    }
    else
        printf("You Entered Wrong");










}
