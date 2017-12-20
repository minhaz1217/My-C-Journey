#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator, denominator;
    public:
        Fraction(int n=0,int d=1):numerator(n), denominator(d){}
        void setData(int n, int d){
            numerator = n;
            denominator = d;
        }
        void setNumerator(int n){
            numerator = n;
        }
        int getNumerator(){
            return numerator;
        }
        void setDenominator(int d){
            denominator = d;
        }
        int getDenominator(){
            return denominator;
        }
        void lowterms(){
            int tnum, tden, temp,gcd;
            tnum = numerator >= 0 ? numerator : (numerator *-1);
            tden = denominator >= 0 ? denominator : denominator *-1;
            if(tnum == 0){
                numerator = 0;
                denominator = 1;
            }
            while(tnum != 0 ){
                if(tnum < tden){
                    temp = tnum;
                    tnum = tden;
                    tden = temp;
                }
                tnum = tnum - tden;
            }
            gcd = tden;
            numerator = numerator/gcd;
            denominator = denominator / gcd;
        }
        void display(){
            cout << numerator << "/" << denominator;
        }
};
Fraction fAdd(Fraction f1, Fraction f2){
    Fraction f((f1.getNumerator()*f2.getDenominator() + f1.getDenominator()*f2.getNumerator()), (f1.getDenominator() * f2.getDenominator()));
    return f;
}
Fraction fSub(Fraction f1, Fraction f2){
    Fraction f((f1.getNumerator()*f2.getDenominator() - f1.getDenominator()*f2.getNumerator()), (f1.getDenominator() * f2.getDenominator()));
    return f;

}
Fraction fMul(Fraction f1, Fraction f2){
    Fraction f((f1.getNumerator()*f2.getNumerator()), (f1.getDenominator() * f2.getDenominator()));
    return f;

}
Fraction fDiv(Fraction f1, Fraction f2){
    Fraction f((f1.getNumerator()*f2.getDenominator()),(f1.getDenominator() * f2.getNumerator()) );
    return f;

}
int main(){

    Fraction frac1,frac2,fAns;
    int n1,d1,n2,d2;
    char choice, extra, ope;
    for(;;){
        cout << "Enter Numbers: (A/B operator C/D): ";
        cin >>  n1 >> extra >> d1 >> ope >>  n2 >> extra >> d2;
        frac1.setData(n1,d1);
        frac2.setData(n2,d2);
        switch(ope){
            case '+':
            fAns = fAdd(frac1,frac2);
            cout << "Ans: ";
            fAns.lowterms();
            fAns.display();
            cout << endl;
            break;
            case '-':
            fAns = fSub(frac1,frac2);
            cout << "Ans: ";
            fAns.lowterms();
            fAns.display();
            cout << endl;
            break;
            case '*':
            fAns = fMul(frac1,frac2);
            cout << "Ans: ";
            fAns.lowterms();
            fAns.display();
            cout << endl;
            break;
            case '/':
            fAns = fDiv(frac1,frac2);
            cout << "Ans: ";
            fAns.lowterms();
            fAns.display();
            cout << endl;
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
