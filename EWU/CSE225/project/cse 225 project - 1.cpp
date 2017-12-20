#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;

double equation(double a){
    return (5*a*a+10);
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

int main(){
    int i,j,n=10;
    double x[n],y[n],value = 10,u,forward,backward,x0 = 8;

    vector<double>del[n];
    for(i=0;i<n;i++){
        x[i] = value;
        del[0].push_back(equation(value));
        msg(x[i], equation(value))
        value += 10;
    }
    for(i=1;i<n;i++){
        for(j=0;j<del[i-1].size()-1;j++){
            del[i].push_back(del[i-1][j+1]-del[i-1][j]);
        }
    }

    //forward method
    u = (x0 - x[0])/ (x[1]-x[0]);
    msg("U", u);
    forward = del[0][0];

    for(i=0;i<n-2;i++){
        forward += del[i+1][0] * calculateForwardTerm(u,i+1);
    }
    cout << "Using Forward:" << forward << endl;


    //backward method
    u = (x0 - x[n-1])/ (x[1]-x[0]);
    msg("U", u);
    backward = del[0][del[0].size()-1];

    for(i=0;i<n-2;i++){
        backward += del[i+1][del[i+1].size()-1] * calculateBackwardTerm(u,i+1);
    }
    cout << "Using Backward:" << backward << endl;




	return 0;
}
