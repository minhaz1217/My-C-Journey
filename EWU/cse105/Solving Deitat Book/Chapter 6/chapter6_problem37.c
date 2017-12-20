/*
6.37 (Find the Minimum Value in an Array) Write a recursive function recursiveMinimum that
takes an integer array and the array size as arguments and returns the smallest element of the array.
The function should stop processing and return when it receives an array of one element.
*/
#include<stdio.h>
main(){
    int recursiveMinimum(int arr[], int arrSize){
        int i,min=arr[0];
        for(i=0;i<arrSize;i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
        return min;
    }

    int a[5] = {1,2,-3,4,5},x;
    x = recursiveMinimum(a, 5);
    printf("%d", x);
}
