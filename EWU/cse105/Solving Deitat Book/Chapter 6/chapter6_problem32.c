/*
6.32 (Linear Search) Modify the program of Fig. 6.18 to use a recursive linearSearch function
to perform the linear search of the array. The function should receive an integer array, the size of
the array and the search key as arguments. If the search key is found, return the array subscript; otherwise,
return –1.
*/

#include<stdio.h>
main(){
    int linearSearch(int a[], int arrSize, int key){
        int i;
        for(i=0;i<arrSize;i++){
            if(a[i] == key){
                return i;
                break;
            }
        }
        return -1;
    }

    int arr[5] = {1,2,3,4,5},x;
    x = linearSearch(arr, 5,2);
    printf("%d", x);
}
