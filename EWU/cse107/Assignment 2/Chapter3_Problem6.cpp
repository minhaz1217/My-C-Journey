#include<iostream>
using namespace std;
int main(){
    int num, sum = 1,i;
    for(;;){
        cout << "Enter a number: ";
        cin >> num;
        if(num == 0){
            break;
        }
        for(i=1;i<=num;i++){
            sum *= i;
        }
        cout << num << "! = " << sum<< endl;
        sum = 1;
    }

    return 0;
}
