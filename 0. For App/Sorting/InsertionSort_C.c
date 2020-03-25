#include<stdio.h>


int arr[] = {5,1,4,2,8},nn;
void insertionSort(int arr[], int n){
    int i=0;
    while(i<n){
        printArr();
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        i++;
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
    insertionSort(arr, nn);
    printArr();
    return 0;
}
