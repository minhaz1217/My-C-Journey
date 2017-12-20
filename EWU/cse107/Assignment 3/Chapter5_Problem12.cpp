#include<iostream>
using namespace std;
struct Fraction{
    int numerator, denominator;
};
Fraction fAdd(Fraction f1, Fraction f2){
    Fraction f;
    f.numerator = (f1.numerator*f2.denominator + f1.denominator*f2.numerator);
    f.denominator = (f1.denominator * f2.denominator);
    return f;
}
Fraction fSub(Fraction f1, Fraction f2){
    Fraction f;
    f.numerator = (f1.numerator*f2.denominator - f1.denominator*f2.numerator);
    f.denominator = (f1.denominator * f2.denominator);
    return f;

}
Fraction fMul(Fraction f1, Fraction f2){
    Fraction f;
    f.numerator = (f1.numerator*f2.numerator) ;
    f.denominator = (f1.denominator * f2.denominator);
    return f;

}
Fraction fDiv(Fraction f1, Fraction f2){
    Fraction f;
    f.numerator = (f1.numerator*f2.denominator);
    f.denominator = (f1.denominator * f2.numerator);
    return f;

}


int main(){
    Fraction frac1,frac2,fAns;
    char choice, extra, ope;
    for(;;){
        cout << "Enter Numbers: (A/B operator C/D): ";
        cin >> frac1.numerator >> extra >> frac1.denominator >> ope >>  frac2.numerator >> extra >> frac2.denominator;

        switch(ope){
            case '+':
            fAns = fAdd(frac1,frac2);
            cout << "Ans: " << fAns.numerator << "/" << fAns.denominator    << endl;
            break;
            case '-':
            fAns = fSub(frac1,frac2);
            cout << "Ans: " << fAns.numerator << "/" << fAns.denominator    << endl;
            break;
            case '*':
            fAns = fMul(frac1,frac2);
            cout << "Ans: " << fAns.numerator << "/" << fAns.denominator    << endl;
            break;
            case '/':
            fAns = fDiv(frac1,frac2);
            cout << "Ans: " << fAns.numerator << "/" << fAns.denominator    << endl;
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
