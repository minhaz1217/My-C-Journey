#include<iostream>
using namespace std;
int main(){
    int i;
    double iAmount, iRate, fAmount;
    cout << "Enter initial amount: ";
    cin >> iAmount;
    cout << "Enter interest rate (percent per year): ";
    cin >> iRate;
    cout << "Enter final amount: ";
    cin >> fAmount;
    iRate = iRate /100;
    for(i=1; iAmount <= fAmount ;i++){
        iAmount += (iAmount * iRate);
    }
    cout << "To reach " << fAmount << " you'll need " << i-1 << " years.";


    return 0;
}
