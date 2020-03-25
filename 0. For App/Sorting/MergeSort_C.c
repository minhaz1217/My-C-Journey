#include<stdio.h>


int arr[] = {5,1,4,2,8},nn;
void mergeSort(int l, int r){
    if(r>l){
        int mid = l + (r-l)/2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, r);
    printf("\n\nParent %d %d\n", l, r);
    printf("Left %d %d\n", l, mid);    printf("Right %d %d\n", mid+1, r);
    printf("After Merge\n");
    printArr();
    }
}
void merge(int l, int r){
    int mid = l + (r-l)/2, n1= mid-l +1, n2 =r- mid;
//    printf("Merge: %d %d %d %d %d\n", l, r, mid, n1, n2);
    int L[n1], R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[mid+1+i];
    }
    int i = 0, j=0,k= l;
    while(i<n1 && j< n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]  = R[j];
        k++;
        j++;
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
    mergeSort(0, nn-1);
    printArr();
    return 0;
}
