#include<stdio.h>


int arr[] = {5,1,4,2,8},nn;
void bubbleSort(int arr[], int n){
    int swapped = 1;
    while(swapped){
        printArr();
        swapped = 0;
        for(int i=1;i<n;i++){
            if(arr[i-1]> arr[i]){
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                swapped = 1;
            }
        }
    }
}

void printArr(){
    for(int i=0;i<nn;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    nn = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr, nn);
    printArr();
    return 0;
}
