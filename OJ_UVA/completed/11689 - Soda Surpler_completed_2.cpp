#include<iostream>
using namespace std;
int main(){
    int a,i,num[3],arrCounter= 0,amount = 0;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        arr[i] = 0;
    }


    for(i=1;i<=a;i++){
        cin >> num[0] >> num[1]>>num[2];
        amount = num[0] + num[1];
        for(;amount != 0;){
            arr[arrCounter] += amount/num[2];
            amount = (amount%num[2]) + (amount/num[2]);
            if(amount < num[2]) break;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i]<< endl;
    }

    return 0;
}
