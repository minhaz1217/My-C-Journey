#include<iostream>
using namespace std;
int main(){
    double dPoint = 3.51,others;
    int pounds, shillings, pence;
    //problem, when others is int the result for others is different


    cout << "Enter decimal points: ";
    cin >> dPoint;

    pounds = static_cast<int>(dPoint);
    others = (dPoint * 100) - (pounds*100);
    shillings = static_cast<int>((others/10)) * 10 / 5;
    others = others - static_cast<int>((others/10)) * 10;
    pence = others * 2.4;
    cout << "Equivalent in old notation = " << "\x9c" << pounds << "."<< shillings<< "." << pence << "." << endl;


    return 0;
}
