#include<iostream>
using namespace std;

int reverseNumber(int number){
    int num = 0;
    while(number!=0){
        num = num*10 + number%10;
        number /= 10;
    }
    return num;
}


int main(){
    int number=0, splitNumber=0;
    cin >> number;
    while(number!=0){
        splitNumber = splitNumber*10 + number%10;
        number /=10;
    }
    cout << reverseNumber(number);
	return 0;
}
