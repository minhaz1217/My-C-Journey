/*
Read the 12 values of floating-point array monthlyTemperatures from the keyboard.
*/

#include<stdio.h>
main(){
    int i, temp;
    float monthlyTemperatures[12];
    for(i=0;i<12;i++){
        printf("Enter the temperatus no %d: ", i+1);
        scanf("%f", &monthlyTemperatures[i]);
    }
}
