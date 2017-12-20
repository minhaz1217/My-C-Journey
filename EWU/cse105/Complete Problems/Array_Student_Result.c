#include<stdio.h>
main(){
    int i,number[5],score;
    score =0;
    for(i=0;i<5;i++){
        number[i] =0;
    }

    for(i=0;i<5;i++){
        printf("Enter Score(0-5): ");
        scanf("%d", &score);
        number[score]++;
    }
    for(i=0;i<5;i++){
        printf("%d is here %d times\n", i, number[i]);
    }
}
