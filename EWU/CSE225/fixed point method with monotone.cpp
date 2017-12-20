#include<bits/stdc++.h>
using namespace std;
double a,b,c, arr[1000];
int arrCounter = 0,i;
double equation(double x){
    return (5/x);
}
double equation2(double x){
    return (-a*x*x- c)/b;
}
double equation3(double x){
    return (10/ (x*x*x -1));
}
double equation4(double x){
    return (x + (5/x))/2;
}

int main(){
    double x0 ,x1 , startPoint = 1,e = 0.01,flag=1,incrementFlag =0,decrementFlag = 0,maxDiff = 10000;
    cout << "Equation: (ax^2 + bx + c) & (b!=0): ";
    cin >> a >> b >> c;
    while(b==0){
        cout << "Enter again: " << endl << "Equation: (ax^2 + bx + c) & (b!=0): ";
        cin >> a >> b >> c;
    }
    x0 = startPoint;
    x1 = equation4(x0); // << change here
    arr[arrCounter++] = x1;
    //while( fabs(x0 - x1) >= e){
    while(x0-x1 != 0){
        x0 = x1;
        x1 = equation4(x0);  // << change here
        arr[arrCounter++] = x1;
        for(i=0;i<arrCounter-1;i++){
            if(arr[i] == x1){
                if(x0 - x1 == 0){
                    cout << x0 << endl;
                }else{
                    cout << "Oscillatory Convergence." << endl;
                }
                    flag = 0;
                    break;
            }else if(fabs(arr[i] - arr[i+1]) >= maxDiff){
                cout << "Monotone Convergence" << endl;
                cout << x0 << " ";
                flag = 0;
                break;
            }
        }
        if(flag == 0 || (x0 - x1) == 0){
            break;
        }

        /*
        if(arrCounter >= 10){
            for(i=0;i< arrCounter;i++){
                if(arr[i+1] > arr[i] ){
                    incrementFlag =1;
                }else if(arr[i+1] < arr[i]){
                    decrementFlag = 1;
                }
            }
        }

        if(arrCounter >= 5 && !(incrementFlag == 1 && decrementFlag == 1)){
            cout << "Monotone Convergence" << endl;
            cout << x0 << " ";
            flag = 0;
            break;
        }
        */

        //cout << x1 << endl;

    }
    cout << x1 << endl;
    return 0;
}
