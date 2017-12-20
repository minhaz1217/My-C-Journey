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
Fraction fMul(Fraction f1, Fraction f2){
    Fraction f((f1.getNumerator()*f2.getNumerator()), (f1.getDenominator() * f2.getDenominator()));
    /*
    f.numerator = (f1.getNumerator()*f2.getNumerator()) ;
    f.denominator = (f1.getDenominator() * f2.getDenominator());
    */
    return f;

}
int main(){
    int a,i,j;
    Fraction result;
    cin >> a;
    Fraction f[a+1];
    cout << "\t";
    for(i=1;i<a;i++){
        f[i].setData(i, a);
        f[i].lowterms();
        f[i].display();
        cout << "\t";
    }
    cout << endl << "---------------------------------------------------------" << endl;
    for(i=1;i<a;i++){
        f[i].display();
        cout << "\t";
        for(j=1;j<a;j++){
            result = fMul(f[i], f[j]);
            result.lowterms();
            result.display();
            cout << "\t";
        }
        cout << endl;
    }

	return 0;
}
