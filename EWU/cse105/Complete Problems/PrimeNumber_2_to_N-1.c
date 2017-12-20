#include<stdio.h>
main(){
    int i, N, flag;
    flag =1;
    N = 21;
    for(i=2;i<N-1;i++){
        if(N%i == 0){
            flag = 0;
            break;
        }
    }

    if(flag == 0){
        printf("The number is not a prime number.");
    }else{
        printf("The number is a prime number.");
    }
}
