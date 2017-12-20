#include<iostream>
using namespace std;
int main(){
    int choice;
    float temperature, convertedTemp =0.00f;
    cout << "Type \t1 to convert Fahrenheit to Celsius,\n\t2 to convert Celsius to Fahrenheit: ";
    cin >> choice;
    switch(choice){
    case 1:
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temperature;
        cout << "In Celsius that's: " << (temperature - 32) * 5/9<< endl;
        break;
    case 2:
        cout << "Enter temperature in Celsius: ";
        cin >> temperature;
        cout << "In Fahrenheit that's: "<< (temperature * 9/5) + 32;
    }





    return 0;
}
