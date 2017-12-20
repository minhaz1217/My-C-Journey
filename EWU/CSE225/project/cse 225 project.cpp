#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;

double equation(double a){
    return (2*a*a+ 3* a + 10);
    //1: return (2*a*a+ 3* a + 10);
    //2: return (5*a*a - 8* a +2);
    //3: return ((9*a/ 2) + 4);
    //5x^2 + 10
}
double factorial(double a){
    double sum = 1;
    for(int i=1;i<=a;i++){
        sum*=i;
    }
    return sum;
}
double calculateForwardTerm(double u, double term){
    double sum = u;
    for(int i=1;i<term;i++){
        sum *= ((double)u-(double)i);
    }
    return (sum/factorial(term));
}

double calculateBackwardTerm(double u, double term){
    double sum = u;
    for(int i=1;i<term;i++){
        sum *= ((double)u+(double)i);
    }
    return (sum/factorial(term));
}
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}

int main(){
    int i,j,n=10;
    double interval, value = 10,u,forward,backward,x0 = 23;


    system("cls");
    SetConsoleTitle("CSE225 Project - Newton's Forward & Backward Interpolation Method");
    changeConsoleColor(27);
    cout <<setw(64) << "" << endl;
    cout << "\tNEWTON's FORWARD & BACKWARD INTERPOLATION METHODS\t" << endl;
    cout <<setw(64) << "" << endl;
    cout << endl;
    changeConsoleColor(240);


    cout << "Enter How many terms of X: ";
    cin >> n;
    double x[n],y[n];
    vector<double>del[n];
    cout << "Enter first Value of X: ";
    cin >> value;
    cout << "Enter interval: ";
    cin >> interval;

    cout << "X  :  Y\n";
    for(i=0;i<n;i++){
        x[i] = value;
        del[0].push_back(equation(value));
        cout << x[i] << " : " << equation(value)<< endl;
        value += interval;
    }
    cout << "Enter Desired value of X: ";
    cin >> x0;
    for(i=1;i<n;i++){
        for(j=0;j<del[i-1].size()-1;j++){
            del[i].push_back(del[i-1][j+1]-del[i-1][j]);
        }
    }

    cout << "\n\nTable: " << endl;
    cout << "X: ";
    for(i=0;i<n;i++){
        cout << x[i] << " ";
    }
    cout << endl;
    for(i=0;i<n;i++){
        cout << "del" << i << " ";
        for(j=0;j<del[i].size();j++){
            cout << fixed << setprecision(2) <<  del[i][j] << " ";
        }
        cout << endl;
    }




    //forward method
    cout << "\n\nForward Method: " << endl;
    u = (x0 - x[0])/ (x[1]-x[0]);
    cout << "U for forward: " << u << endl;
    forward = del[0][0];

    for(i=0;i<n-2;i++){
        forward += del[i+1][0] * calculateForwardTerm(u,(double)(i+1));
    }
    cout << "Using Forward Method:" << forward << endl;


    //backward method
    cout << "\n\nBackward Method: " << endl;
    u = (x0 - x[n-1])/ (x[1]-x[0]);
    cout << "U for Backward method: " << u << endl;
    backward = del[0][del[0].size()-1];

    for(i=0;i<n-2;i++){
        backward += del[i+1][del[i+1].size()-1] * calculateBackwardTerm(u,(double)(i+1));
    }
    cout << "Using Backward Method:" << backward << endl;




	return 0;
}
