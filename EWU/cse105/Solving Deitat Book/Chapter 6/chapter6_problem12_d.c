/*
Print the five values of integer array bestScores in column format.
*/
#include<stdio.h>
main(){
    int bestScores[5],i;
    for(i=0;i<5;i++){
        bestScores[i] = 0;
        printf("Best score %d is: %d\n", i+1, bestScores[i]);
    }
}
