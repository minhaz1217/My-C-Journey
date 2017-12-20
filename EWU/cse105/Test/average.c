#include<stdio.h>
main(){
    int num, count=0, sum=0;
    float avg =0.0;

    for(;;){
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num == 0){
            break;
        }else{
            sum += num;
            count++;
        }
    }
    avg = (float)sum/count;
    printf("Total is: %d, Average is: %f", sum, avg);
}
