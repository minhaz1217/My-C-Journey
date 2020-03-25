#include<stdio.h>


int arr[] = {5,1,4,2,8},nn;
void selectionSort(int arr[], int n){
    int minIndex;
    for(int i=0;i<n-1;i++){
        printArr();
        minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    selectionSort(arr, nn);
    printArr();
    return 0;
}
