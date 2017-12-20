#include<stdio.h>
main(){
    int i, N, flag;
    flag =1;
    N = 13;
    if(N%2 == 0){
        flag = 0;
    }else{
        for(i=3;i<N-1;i += 2){
            if(N%i == 0){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        printf("The number is not a prime number.");
    }else{
        printf("The number is a prime number.");
    }
}
