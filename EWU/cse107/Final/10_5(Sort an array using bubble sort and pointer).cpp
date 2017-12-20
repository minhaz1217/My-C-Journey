#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,4,2,5,3};
    int *ptr;
    int temp;
    ptr = arr;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if((*(ptr+j)) < (*(ptr+i)) ){
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << *(ptr+i) << endl;
    }
	return 0;
}
