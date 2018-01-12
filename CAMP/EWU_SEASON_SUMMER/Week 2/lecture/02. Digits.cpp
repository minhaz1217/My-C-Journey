#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;



long long int fact(long long int  n){
    if(n == 1){
        return 1;
    }
    return n*fact(n-1);
}
long long int  numOfDigits(long long int  n){
    long long int  digits = 0;
    while(n != 0){
        digits++;
        n = n/10;
    }
    return digits;
}
long long int  numOfDigitsOf2Numbers(long long int  a,long long int  b){
    long long int  digits = 0;
    a *= b;
    return numOfDigits(a);
}
long long int numOfDigitsPower(long long int n, long long int  p){
    n = pow(n, p);
    return numOfDigits(n);
}
long long int  numOfDigitsInFactorial(long long int n){
    return numOfDigits(fact(n));
}
int sumOfDigitsInADigit(long long int n){
    int sum= 0;
    while(n!= 0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}
int sumOfDigitsInADigitUntilItBecomesOneDigit(long long int n){
    int sum= 0;
    while(n!= 0){
        sum += n%10;
        n = n/10;
    }
    if(sum / 10 == 0){
        return sum;
    }else{
        return sumOfDigitsInADigitUntilItBecomesOneDigit(sum);
    }
}
int trailingZeroOfFactorial(int n){
    int trZero = 0;
    n = fact(n);
    while(n != 0){
        if(n %10==0){
            trZero++;
        }else{
            break;
        }

        n = n/10;
    }
    return trZero;
}

long long int NODi(long long int n){
    return ceil(log10(n));
}

long long int NODiMulti(long long int a, long long int b){
    return (ceil(log10(a)+ log10(b)));
}

long long int NODiPow(long long int n, long long int p){
    return ceil(p * log10(n));
}
long long int factD(int a, int b){
}
long long int NODiFact(int n){
    double nod = 0;
    for(int i=1;i<= n;i++){
        nod += log10(i);
    }
    return ceil(nod);
    //else return no
}
long long int trailingZeroLoop(int n){
    int sum = 0;
    while(n){
        n =n/5;
        sum += n;
    }
    return sum;
}
long long int trailingZeroEff(int n){
    int sum = 0, i =1,x;
    do{
        x = n/pow(5, i++);
        sum+=x;
    }while(x);
    return sum;
}



int main(){
    int a=30;
    //check(fact(a))
    //check(sumOfDigitsInADigitUntilItBecomesOneDigit(a))
    //check(trailingZeroOfFactorial(a))
    /*
    check(NODiMulti(999,999))
    check(NODiPow(15,15))
    check(NODiPow(10,5))
    check(NODiPow(15,5))
    */
    check(trailingZeroLoop(100))
    check(trailingZeroEff(100))
    //check(NODiMulti(15,25))

    return 0;
}
