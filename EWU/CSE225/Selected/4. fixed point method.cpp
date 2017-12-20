#include<bits/stdc++.h>
using namespace std;
/*
Input:
1 -4 -10
Answer: -1.74 or 5.74112
Input:
1 -1 -2
Answer : 2,-1

*/


double a,b,c, arr[1000];
int arrCounter = 0,i;


double inputEquation(double x){
    return (-a*x*x- c)/b;
}

double equation(double x){
    return (5/x);
}
double equation3(double x){
    return (10/ (x*x*x -1));
}
double equation4(double x){
    return exp(-x);
}

int main(){
    double x0 ,x1 , startPoint = 0,e = 0.01,flag=1;
    cout << "Equation: (ax^2 + bx + c) & (b!=0): ";
    cin >> a >> b >> c;
    while(b==0){
        cout << "Enter again: " << endl << "Equation: (ax^2 + bx + c) & (b!=0): ";
        cin >> a >> b >> c;
    }
    x0 = startPoint;
    arr[arrCounter++] = x0;
    x1 = inputEquation(x0);
    arr[arrCounter++] = x1;
    //while( fabs(x0 - x1) >= e && flag){
    while(x0-x1 != 0 && flag ){
        x0 = x1;
        x1 = inputEquation(x0);
        arr[arrCounter++] = x1;
        for(i=0;i<arrCounter-1;i++){
            if(arr[i] == x1){
                if(fabs(x0 - x1) <= e){
                    //cout << x1 << endl;
                }else{
                    //cout << x0 << endl;
                    cout << "Oscillatory Convergence: " << x0 << endl;
                    return 0;
                }
                flag = 0;
                break;
            }
        }
        cout << x0 << " DIFF: " << (float)(x0 - x1) << endl;
    }
    cout << x1 << endl;
    return 0;
}
