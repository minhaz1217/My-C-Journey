#include<iostream>
using namespace std;
struct BritishOld{
    int pounds, shillings, pence;
};

int main(){
    BritishOld b1;
    double dPoint,others;
    cout << "Enter decimal points: ";
    cin >> dPoint;

    b1.pounds = static_cast<int>(dPoint);
    others = (dPoint * 100) - (b1.pounds*100);
    b1.shillings = static_cast<int>((others/10)) * 10 / 5;
    others = others - static_cast<int>((others/10)) * 10;
    b1.pence = others * 2.4;
    cout << "Equivalent in old notation = " << "\x9c" << b1.pounds << "."<< b1.shillings<< "." << b1.pence << "." << endl;


	return 0;
}
