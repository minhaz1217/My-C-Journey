#include<iostream>
#include<math.h>
using namespace std;
int *getNumberStartToEnd(int number){
    int temp = number, counter = 1,arr[20],arrCounter = 0;
    while(temp!=0){
        counter *=10;
        temp = temp/10;
    }
    for(temp = counter/10;temp!=0;temp/=10){
        arr[arrCounter++] = number/temp;
        number = number%temp;
    }
    return arr;
}


int main(){
    int number,extra,i,counter = 1,temp;
    cin >> number;
    /*
    temp = number;
    while(temp!=0){
        counter *=10;
        temp = temp/10;
    }
    for(i=counter/10;i!=0;i /= 10){
        cout << static_cast<int>(number/i) << endl;
        number = number%i;
    }
*/
    int *arraye;
    arraye = getNumberStartToEnd(number);
    cout << arraye[1];
    //cout << number / pow(10, counter-2);


	return 0;
}
