#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int i, num1, num2,counter = 0,res[1000],resCounter = 0;
    for(;;){
        cin >> num1;
        cin >> num2;
        if(num1 == 0 && num2 == 0) break;
        counter = sqrt(num2);
        for(i=sqrt(num2); pow(i,i)>= num1;i--){
        }
        if(i!= -1){
            counter = counter - i;
        }
        res[resCounter] = counter;
        resCounter++;
    }
    for(i=0;i<resCounter;i++){
        cout << res[i]<<  endl;
    }
    return 0;
}
