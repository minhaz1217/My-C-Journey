#include<stdio.h>
main(){
    int i,a;
    a = 25;
    for(i=1;i<=a;i++){
        printf("%2d ", i);
        if(i%5 == 0){
            printf("\n");
        }
    }
}
