#include<iostream>
using namespace std;
int main(){
    int num1, num2,prev=0,carryCounter = 0,temp,n1,n2,arrCounter = 0, arr[100000];
    for(;;){
        prev = 0;
        cin >> num1 >> num2;
        if(num1 ==0 && num2 ==0){break;}
        if(num1 < num2){
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        while(num1!=0){
            n1 = num1 % 10;
            n2= num2 % 10;
            if(n1+n2+prev >= 10){
                carryCounter++;
                prev = 1;
            }else{
                prev = 0;
            }
            num1 = num1/10;
            num2 = num2/10;
        }
        arr[arrCounter] = carryCounter;
        arrCounter++;
        carryCounter = 0;
    }
    for(num1=0;num1<arrCounter;num1++){
        if(arr[num1] == 0){
            cout << "No carry operation." << endl;
        }else if(arr[num1] == 1){
            cout << "1 carry operation." << endl;
        }else{
            cout << arr[num1] << " carry operations." << endl;
        }
    }

	return 0;
}
