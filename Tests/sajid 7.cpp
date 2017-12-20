#include<stdio.h>
int main(){
    int arr[100],n,i,j,temp,counter = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]< arr[i]){
                temp = arr[j];
                arr[j]=arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("After sortring the arr is: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    temp = arr[2];
    for(i=0;i<n;i++){
        if(arr[i]> temp){
            counter++;
        }
    }
    printf("\n\n");
    printf("%d number are bigger than at least 3 numbres", counter);

}
