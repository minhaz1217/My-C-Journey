#include<iostream>
using namespace std;
int main(){
    int a,i,j,arrCounter = 0,num, sum = 0,arr[2000];
    for(;;){
        cin >> num;
        if(num < 0){
            break;
        }
        sum = 1;
        for(j=1;sum<num;j++){
            sum = sum*2;
        }
        cout << j-1 << endl;
        /*
        arr[arrCounter] = j-1;
        arrCounter++;*/
    }/*
    for(i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": " << arr[i]<< endl;

    }

*/
    return 0;
}
