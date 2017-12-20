#include<iostream>
using namespace std;
int main(){
    double amount, convertedAmount;

    cout << "Enter the dollar value you want to convert: ";
    cin >> amount;

    cout << "The Pound value for this is: " << (amount/1.487) << endl;
    cout << "The French Franc value for this is: " << (amount/0.172) << endl;
    cout << "The German Deutschemark value for this is: " << (amount/ 0.584) << endl;
    cout << "The Japanese Yes value for this is: " << (amount/ 0.00955 )<< endl;



    return 0;
}
