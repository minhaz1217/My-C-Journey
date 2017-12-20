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
double calculateNext(double x1, double x2){
    return (x1 - (calculateFunction(x1)*(x2-x2))/(calculateFunction(x2)-calculateFunction(x1)) );
}


int main(){
    double f1,f2,x0,fx0,i1,i2,e = 0.01,temp;
    cout << "Enter a,b,c, (aX^2 + bX +c =0): ";
    cin >> a >> b >> c;
    cout << "Enter Intervals: ";
    cin >>i1 >> i2;
    if(i1 > i2){
        temp = i1;
        i1 = i2;
        i2 = temp;
    }
    f1 = calculateFunction(i1);
    f2 = calculateFunction(i2);
    x0 = calculateNext(i1,i2);
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
