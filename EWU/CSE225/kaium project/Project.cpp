#include<bits/stdc++.h>

using namespace std;

/// For getting value of Y
double solve(double x){
    return (x*x-9*x+24);
}
/// For factorial
double factorial(long long a){
    double sum = 1;
    for(int i = 1 ; i <= a ; i++){
        sum *= i;
    }
    return sum;
}

int main(){

    double x0,h,temp,x[10],y[10][10],u,v,mini,rule=0,ans=0;
    long long s,p;

    cout << "Enter the Initial Value, X0: " ;
    cin >> x[0];
    cout << "Enter the Difference, H: ";
    cin >> h ;

        temp=x[0];

    for(int i = 0 ; i < 10 ;  i++){
        x[i] = temp;
        temp += h;
        y[0][i] = solve(x[i]); /// Assigning value of Y
    }
        for(int i = 1 ; i < 10 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                if(j > 9 - i){
                        y[i][j]=0;
                }
                else{
                    y[i][j] = (y[i-1][j+1]-y[i-1][j]); /// Getting the difference
                }
            }
        }

    cout << "Enter 'X' to get the Required Value: " ;
    cin >> v;

    /// Finding y0
        mini = fabs(x[0] - v);
        s=0;
    for(int i = 0 ; i < 10 ; i++){
        if(fabs(x[i] - v) < mini){
            s = i;
            mini = fabs(x[i] - v);
        }
    }
    /// determine forward or backward
    if(fabs(x[0] - v) < fabs(x[9] - v)){
        if(v - x[s] < 0){
            s--;
        }
        rule=1;
    }
    else if(fabs(x[0] - v) > fabs(x[9] - v)){
        if(v - x[s] > 0){
            s++;
        }
         rule=-1;
    }
    u = (v - x[s])/h; /// value of u wher x[s] = x0

    /// Forward Rule
    if(rule == 1){
        ans = y[0][s] + u*y[1][s];
        if(s-1 >= 0){
                p = 2;
            ans += (u*(u-1)*y[p][s-1]/factorial(p) + (u+1)*u*(u-1)*y[p+1][s-1]/factorial(p+1));
            cout << ans << endl;
        }
        if(s-2 >= 0){
            p=4;
            ans += ((u+1)*u*(u-1)*(u-2)*y[p][s-2]/factorial(p) + (u+2)*(u+1)*u*(u-1)*(u-2)*y[p+1][s-2]/factorial(p+1));
        }
        if(s-3 >= 0){
            p=6;
            ans += ((u+2)*(u+1)*u*(u-1)*(u-2)*(u-3)*y[p][s-3]/factorial(p) + (u+3)*(u+2)*(u+1)*u*(u-1)*(u-2)*(u-3)*y[p+1][s-3]/factorial(p+1));
        }
        if(s-4 >= 0){
            p=8;
            ans += ((u+3)*(u+2)*(u+1)*u*(u-1)*(u-2)*(u-3)*(u-4)*y[p][s-4]/factorial(p) + (u+4)*(u+3)*(u+2)*(u+1)*u*(u-1)*(u-2)*(u-3)*(u-4)*y[p+1][s-4]/factorial(p+1));
        }
    }
    /// Backward Rule
    if(rule == -1){
        ans = y[0][s];
        if(s-1 >= 0){
                p = 1;
            ans += (u*y[p][s-1]/factorial(p) + u*(u+1)*y[p+1][s-1]/factorial(p+1));
        }
        if(s-2 >= 0){
            p=3;
            ans += ((u-1)*u*(u+1)*y[p][s-2]/factorial(p) + (u-1)*u*(u+1)*(u+2)*y[p+1][s-2]/factorial(p+1));
        }
        if(s-3 >= 0){
            p=5;
            ans += ((u-2)*(u-1)*u*(u+1)*(u+2)*y[p][s-3]/factorial(p) + (u-2)*(u-1)*u*(u+1)*(u+2)*(u+3)*y[p+1][s-3]/factorial(p+1));
        }
        if(s-4 >= 0){
            p=7;
            ans += ((u-3)*(u-2)*(u-1)*u*(u+1)*(u+2)*(u+3)*y[p][s-4]/factorial(p) + (u-3)*(u-2)*(u-1)*u*(u+1)*(u+2)*(u+3)*(u+4)*y[p+1][s-4]/factorial(p+1));
        }
        if(s-5 >= 0){
            p=9;
            ans += ((u-4)*(u-3)*(u-2)*(u-1)*u*(u+1)*(u+2)*(u+3)*(u+4)*y[p+1][s-5]/factorial(p+1));
        }
    }
    cout << endl << endl << endl;
    /// Printing the table
    printf("   X\t   Y\t  Y1\t  Y2\t Y3\t Y4\t Y5\t Y6\t Y7\t Y8\t Y9\n");
    for(int i = 0 ; i < 10 ; i++){
            printf("%.2lf\t",x[i]);
            printf("%.2lf\t",y[0][i]);
            if(i<9){
                printf("%.2lf\t",y[1][i]);
            }
            if(i<8){
                printf("%.2lf\t",y[2][i]);
            }
            if(i<7){
                printf("%.2lf\t",y[3][i]);
            }
            if(i<6){
                printf("%.2lf\t",y[4][i]);
            }
            if(i<5){
                printf("%.2lf\t",y[5][i]);
            }
            if(i<4){
                printf("%.2lf\t",y[6][i]);
            }
            if(i<3){
                printf("%.2lf\t",y[7][i]);
            }
            if(i<2){
                printf("%.2lf\t",y[8][i]);
            }
            if(i<1){
                printf("%.2lf\t",y[9][i]);
            }
            printf("\n");

    }
    /// Printing Result
    if(rule==1){
        cout << endl << endl << "Using Gauss Forward Central Difference Interpolation Formula: " <<endl << endl;
    }
    else{
        cout << endl << endl << "Using Gauss Backward Central Difference Interpolation Formula: " <<endl << endl;
    }
    cout << "Here," << endl;
    cout << "U = " << u << endl;
    cout << "X0 = " << x[s] << " , Y0 = " << y[0][s] << endl;
    cout << endl << "The Value of 'Y' for " << v << " is : " << ans << endl;



    return 0;
}
