/*
6.35 (Print an Array) Write a recursive function printArray that takes an array and the size of
the array as arguments, prints the array, and returns nothing. The function should stop processing
and return when it receives an array of size zero.
*/

#include<stdio.h>
main(){
    void printArray(int arr[], int arrSize){
        int i;
        if(arrSize != 0){
            for(i=0;i<arrSize;i++){
                printf("%d\n", arr[i]);
            }
        }
    }

    int a[5] = {1,2,3,4,5};
    printArray(a, 5);
}
