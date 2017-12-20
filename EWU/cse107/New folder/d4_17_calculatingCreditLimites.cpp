#include<iostream>
using namespace std;
int main(){
    int accountNumber[3], creditLimit[3], currentBalance[3], i, newLimit;

    for(i=1;i<=3;i++){
        cout << "Enter Account Number of Customer " << i<< ": ";
        cin >> accountNumber[i-1];
        cout << "Enter Credit Limit of Customer " << i<< ": ";
        cin >> creditLimit[i-1];
        cout << "Enter Current Balance of Customer " << i<< ": ";
        cin >> currentBalance[i-1];
    }
    for(i=0;i<3;i++){
        newLimit = creditLimit[i]/2;
        cout << "\nThe new limit of customer "<< i+1 <<" is " << newLimit;
        if(newLimit < currentBalance[i]){
            cout << "\nCustomer "<< i+1 << " has exceeded their new credit limits";
        }
    }



return 0;
}
