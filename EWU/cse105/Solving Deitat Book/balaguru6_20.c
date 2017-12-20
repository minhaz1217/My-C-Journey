#include<stdio.h>
main(){
    int i,sum=0, num=0,counter =0;
    for(i=1;i<=10;i++){
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num >= 0){
            sum += num;
            counter++;
            if(sum >= 999){break;}
        }
    }
    printf("Numbers Added %d, the sum: %d", counter, sum);
}
