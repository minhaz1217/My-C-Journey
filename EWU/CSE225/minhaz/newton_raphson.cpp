#include<bits/stdc++.h>
using namespace std;
double a,b,c;
double equation(double x){
    return (a*x*x + b*x +c);
}
double equation2(double x){
    return (2*x*a + b);
}
double findNext(double x1){
    double eq1 = equation(x1);
    double eq2 = equation2(x1);
    double ans = (x1 - (eq1 / eq2));
    //cout << "Eq1: " << eq1 << " Eq2: " << eq2 << endl;
    //cout << ans << endl;
    return ans;
}

int main(){
    double x0 = 0, x1, e = 0.01;
    cout << "The equation is: ax^2 + bx + c" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: " ;
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    x1 = findNext(x0);
    while(fabs(x1-x0) >= e){
        x0 = x1;
        x1 = findNext(x0);
    }
    cout << "Difference: " << fabs(x1 - x0) << endl;
    cout << "Result: " << x1 << endl;
    return 0;
}
