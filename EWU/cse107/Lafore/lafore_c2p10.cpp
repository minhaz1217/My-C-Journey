#include<iostream>
using namespace std;
int main(){
    int pounds, shillings, pence;
    double total;
    cout << "Enter pounds: ";
    cin >> pounds;
    cout << "Enter shillings: ";
    cin >> shillings;
    cout << "Enter pence: ";
    cin >> pence;
    total = static_cast<double>(shillings)*5 + static_cast<double>(pence)/2.4;
    cout <<"Decimal pounds = "<< "\x9c" << pounds + total/100<<endl;
    return 0;
}

/*
New system : 
1 shilling = 5 pence
2.4 old.pence = 1 pence

1pound = 20 shillings
1 shillings = 12 pence
1 pounds = 240 pence;

1 pound = 100 pence;
1 shilling = 5 pence


*/

