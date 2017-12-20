#include<bits/stdc++.h>
using namespace std;
/*
Input:
1 -4 -10
secant Xi-1 = 4, Xi = 2
Answer: -1.74 or 5.74
*/
double a,b,c;
double eq1(double x){
    return (a*x*x + b*x + c);
}
double eq2(double x){
    return (2*a*x + b);
}
double newtonRaphsonNext(double x){
    return (x - (eq1(x)/ eq2(x)));
}

// input Xi-1 and Xi in this order
double sacentNext(double x1, double x2){
//finding out x3
return (x2 - ((eq1(x2)*(x2 - x1) / (eq1(x2) - eq1(x1))) ));
}
int main(){
    double x3, x2,x1,nrX0, nrX1 = 0,e = 0.01;
    cout << "The equation is (aX2 + bX + c)." << endl;
    cout << "Input for a: ";
    cin >> a;
    cout << "Input for b: ";
    cin >> b ;
    cout << "Input for c: ";
    cin >> c;
    cout << "Input Xi-1 for Secant method: ";
    cin >> x1;
    cout << "Input Xi for Secant method: ";
    cin >> x2;

    //newton raphson method
    nrX0 = newtonRaphsonNext(nrX1);
    while(fabs(nrX0 - nrX1) >= e ){
        nrX1 = nrX0;
        nrX0 = newtonRaphsonNext(nrX1);
    }
    cout << "Newton Raphson Result: " << (nrX0) << endl;

    //secant method
    x3 = sacentNext(x1, x2);
    while(fabs(eq1(x3)) >= e){
        x1 = x2;
        x2 = x3;
        x3 = sacentNext(x1, x2);
    }
    cout << "Secant Method Result: " << x3 << endl;


    return 0;
}
