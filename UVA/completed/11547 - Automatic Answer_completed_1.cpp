#include<iostream>
using namespace std;
int main(){
    int num, a,i,arrCounter = 0;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        cin >> num;
        num = (((num*567/9) +7492)*235/47)-498;
        num = (num % 100)/10;
        if(num < 0){
            num = num*-1;
        }
        arr[arrCounter] = num;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
