#include<iostream>
using namespace std;
int sumNum(int num){
    int i;
    i=0;
    for(;num > 0;){
        i+= num % 10;
        num = num/10;
        if(num == 0 && i/10 != 0){
            num = i;
            i=0;
        }
    }
    return i;
}
int main(){
    int i=0,num,arrCounter = 0,arr[1000];

    for(;;){
        cin >> num;
        if(num==0){
            break;
        }
        arr[arrCounter] = sumNum(num);
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout <<arr[i] << endl;
    }


    return 0;
}
