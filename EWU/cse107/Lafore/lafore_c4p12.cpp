#include<iostream>
using namespace std;
struct Fraction{
    int numerator, denominator;
};
int main(){
    Fraction f1,f2;
    char choice, extra, ope;
    for(;;){
        cout << "Enter Numbers: (A/B operator C/D): ";
        cin >> f1.numerator >> extra >> f1.denominator >> ope >>  f2.numerator >> extra >> f2.denominator;

        switch(ope){
            case '+':
            cout << "Ans: " << (f1.numerator*f2.denominator + f1.denominator*f2.numerator) << "/" << (f1.denominator * f2.denominator)    << endl;
            break;
            case '-':
            cout << "Ans: " << (f1.numerator*f2.denominator - f1.denominator*f2.numerator) << "/" <<  (f1.denominator * f2.denominator) << endl;
            break;
            case '*':
            cout << "Ans: " << (f1.numerator*f2.numerator) << "/" <<  (f1.denominator * f2.denominator) << endl;
            break;
            case '/':
            cout << "Ans: " << (f1.numerator*f2.denominator) << "/" <<  (f1.denominator * f2.numerator) << endl;
            break;
            default:
                cout << "Something went wrong, Please try again." << endl;
        }
        cout <<"Do another (y/n)?";
        cin >> choice;
        if(choice == 'n'){
            break;
        }else{
            continue;
        }
    }


    return 0;
}
