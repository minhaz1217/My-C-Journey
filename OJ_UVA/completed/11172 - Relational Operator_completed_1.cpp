#include<iostream>
using namespace std;
int main(){
    int i, a, num1,num2, arr[1000],arrCounter = 0;
    cin >> a;
    for(i=1;i<=a;i++){
        cin >> num1 >> num2;
        if(num1 > num2){
            arr[arrCounter] = 2;
        }else if(num1 < num2){
            arr[arrCounter] = 1;
        }else{
            arr[arrCounter] = 0;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        if(arr[i] == 2){
            cout << ">" << endl;
        }else if(arr[i] == 1){
            cout << "<" << endl;
        }else if(arr[i] == 0){
            cout << "=" << endl;
        }
    }
    return 0;
}
