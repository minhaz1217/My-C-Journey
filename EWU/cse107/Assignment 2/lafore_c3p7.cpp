#include<iostream>
using namespace std;
int main(){
    int years, i ;
    double interestRate, iAmount = 0;
    cout << "Enter initial amount: ";
    cin >> iAmount;
    cout <<"Enter number of years: ";
    cin >> years;
    cout << "Enter interest rate (percent per year): ";
    cin >> interestRate;
    interestRate = interestRate/100;
    for(i=1;i<=years;i++){
        iAmount += (iAmount * interestRate);
    }
    cout <<"At the end of " << years << " years, you will have " << iAmount << " dollars";


    return 0;
}
