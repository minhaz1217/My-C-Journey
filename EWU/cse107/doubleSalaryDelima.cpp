#include<iostream>
using namespace std;
int main(){
    double amount = .01, sum = 0;
    for(int i=1;i<=26;i++){
        sum += amount;
        amount = amount * 2;
    }
    cout << sum;
    return 0;
}
