#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {1,2,1,6,4,5,6,10,1};
    int arr2[] = {20,50,30};
    int arr3[12];
    int arrLength = 9;
    int *ptr;


    ptr = find(arr,arr+arrLength, 6);
    cout << "First object with value 6 was at: " << (ptr-arr) << endl;


    int n = count(arr, arr+arrLength,1);
    cout << "1 occured " << n << " times in this array" << endl;


    sort(arr,arr+arrLength);
    cout << "After sorting: ";
    for(int i=0;i<arrLength;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "After the merge: ";
    merge(arr,arr+arrLength, arr2, arr2+3, arr3);
    for(int i=0;i< arrLength+3;i++){
        cout << arr3[i] << " ";
    }
    cout << endl;




	return 0;
}
