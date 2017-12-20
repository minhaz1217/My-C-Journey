#include<bits/stdc++.h>
using namespace std;
/*
Input:
1 -4 -10
-2 -1
Answer: -1.74
Input:
1 -1 -2
1 3
Answer : 2
*/
double a,b,c;
double calculateFunction(double x){
    return (a*x*x + b*x+c);
}


int main(){
    double f1,f2,x0,fx0,i1,i2,e = 0.01;
    cout << "Enter a,b,c, (aX^2 + bX +c =0): ";
    cin >> a >> b >> c;
    cout << "Enter Interval: ";
    cin >>i1 >> i2;
    f1 = calculateFunction(i1);
    f2 = calculateFunction(i2);
    x0 = (i1+i2)/2;
    fx0 = calculateFunction(x0);
    while(fabs(fx0) > e){
        f1 = calculateFunction(i1);
        f2 = calculateFunction(i2);
        x0 = (i1+i2)/2;
        fx0 = calculateFunction(x0);
        if(f1*fx0 < 0){
            i2 = x0;
        }else if(f2 * fx0 < 0){
            i1 = x0;
        }
    }
    cout <<"Answer: " <<  x0 << endl;

	return 0;
}
