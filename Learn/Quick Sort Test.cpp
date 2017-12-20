#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int arr[10] = {8,5,4,6,9,2,3,7,1,0};
void printArr(){
    for(int i =0;i<10;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapFunction(int leftIndex, int rightIndex) {

   int temp = arr[leftIndex];
   arr[leftIndex] = arr[rightIndex];
   arr[rightIndex] = temp;
   printArr();

}
int partitionFunction(int left, int right, int pivot) {

   int leftPointer = left -1;
   int rightPointer = right;

   while(true) {

      while(arr[++leftPointer] < pivot) {
         //do nothing
      }

      while(rightPointer > 0 && arr[--rightPointer] > pivot) {
         //do nothing
      }

      if(leftPointer >= rightPointer)
         break;
      else
         swapFunction(leftPointer,rightPointer); //swaping between arr[leftPointer] and arr[rightPointer]

   }

   swapFunction(leftPointer,right);

   return leftPointer;
}
void quickSort(int left,int right){
    if(right - left <= 0){
        return;
    }else{
        int pivot = arr[right];
        int partitionPoint = partitionFunction(left, right, pivot);
        cout << "Devided" << endl;
        quickSort(left, partitionPoint - 1);
        quickSort(partitionPoint +1, right);
    }
}



int main(){
    printArr();

    quickSort(0, 9);
    printArr();




	return 0;
}
