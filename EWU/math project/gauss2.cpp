#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int variables,y,x,ty,tx;
float arr[1000][1000];
float solutionset[1000];
string solutionString[100];
vector<string>vec;
char marker = 'x';
/*
3
5 4 3 2
9 8 7 6
4 3 2 1
*/
void display(){
    int i,j;
    //cout << endl;
    for(i=1;i<=y;i++){
        for(j=1;j<=x;j++){
            cout << " " << arr[i][j] << " ";
            //printf("%.1lf  ", arr[i][j]);
            //cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rowswap(int row1, int row2){
    int j;
    printf("Swaping R%d with R%d\n", row1, row2);
    for(j=1;j<=x;j++){
        swap(arr[row1][j], arr[row2][j]);
    }
}
void getSolution(){
    stack<int> st;

}


void checkForZeroRow(){
    int i,j,flag = 1;
    // if flag == 1 then there is a zero row
    for(i=1;i<=ty;i++){
        flag = 1;
        for(j=1;j<=tx;j++){
            if(arr[i][j] != 0){

                //cout << arr[i][j] << endl;
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("All zero row exists. Swaping Row%d with Row%d", i, ty);
            rowswap(i, ty);
            ty--;
            // ty decreases by 1 because we don't need any loop that goes to the last row
        }
    }
}

void displayEquation(){
    int i,j;
    cout << "System of Equation:" << endl;
    for(i=1;i<=y;i++){
        for(j=1;j<x;j++){
            if(j>1 && arr[i][j] < 0){
                cout << " - " << arr[i][j]*-1 << marker << j;
                // the *-1 is so that the number shows positive and the minus is from OUR given minus
                // otherwise it shows 2 minuses
            }else if(arr[i][j] == 0){
                cout << "     ";
            }else if(j>1){
                cout << " + " << arr[i][j] << marker << j;
            }else{
                cout << arr[i][j] << marker << j;
            }
        }
        if(arr[i][j] < 0){
            cout << " - " << arr[i][j] *-1;
        }else{
            cout << " + " << arr[i][j];
        }
        cout << " = 0 " << endl;
    }
}
void initWithDefault(){
    variables = 3;
    y = variables;
    x = variables+1;
    ty = y;
    tx = x;

    arr[1][1] = 5;
    arr[1][2] = 4;
    arr[1][3] = 3;
    arr[1][4] = 2;

    arr[2][1] = 9;
    arr[2][2] = 8;
    arr[2][3] = 7;
    arr[2][4] = 6;

    arr[3][1] = 4;
    arr[3][2] = 3;
    arr[3][3] = 2;
    arr[3][4] = 1;

    displayEquation();
}
void displaySolution(){
    int i;
    for(i=1;i<x;i++){
        cout << "x" << i << " = " << solutionset[i] << endl;
        //msg(i, solutionset[i])
    }
}
void takeInput(){
    int i,j;
    cout << "How many variables?: ";
    cin >> variables;
    y = variables;
    x = variables+1;
    ty = y;
    tx = x;

    for(i=1;i<x;i++){
        solutionset[i] = 0;
    }
    cout << "Sample: ax1 + bx2 .....+ ijxN = 0" << endl;
    for(i=1;i<=ty;i++){
        for(j =1;j<=tx;j++){
            printf("Enter for R%dC%d: ", i,j);
            cin>> arr[i][j];
        }
    }
    cout << endl;
    displayEquation();
}
void gaussEliminationMethod(){
    int r,c,swapPossible,i,j,foundOne;
    float divide,multi,temp,sum;
    for(r = 1,c=1;r<=ty;r++,c++){
        checkForZeroRow();
        swapPossible = 0;
        if(arr[r][c] == 0){
            for(i=r;i<=tx;i++){
                if(arr[i][c] != 0){
                    swapPossible = 1;
                    rowswap(r, i);
                    break;
                }

            }
            // if no swap is possible then we just skip that row and that column
            if(swapPossible != 1){
                continue;
            }
        }
        divide = arr[r][c];
        if(divide == 0){
            display();
            continue;
        }
        printf("Divide row %d by %.1lf\n", r, divide);

        //making row's first element 1
        for(i=c;i<=tx;i++){
            arr[r][i] = arr[r][i] / divide;
        }
        display();
        for(i=r+1;i<=ty;i++){
            cout << "Row" << i << " = Row" << i << " - (" << arr[i][c] << ") * Row"<< r<< endl;
            //printf("Row%d = Row%d - (%.1lf) * Row%d\n", i, i, arr[i][c], r);
            multi = arr[i][c];
            for(j=c;j<=tx;j++){
                temp =  arr[i][j] - (multi * arr[r][j]);
                //arr[i][j] = arr[i][j] - (multi * arr[r][j]);
                arr[i][j] = temp;

                //cout << arr[i][c] << endl;
            }
        }
        cout << endl;
        display();
    }
    // solution
    //if foundOne ==0 then we know that is all zero row
    for(r=y;r>=1;r--){
        foundOne = 0;
        sum =0;
        for(c = 1;c<=x;c++){
            if(arr[r][c]==1){
                foundOne = 1;
                for(i=c+1;i<=x;i++){
                    if(i==x){
                        sum -= arr[r][i];
                    }else{
                        sum = sum - arr[r][i]*solutionset[i];
                    }
                }
                solutionset[c] = sum;
            }
        }
    }
    cout << "Final" << endl;
    display();

}

void gaussEliminationMethod2(){
    int i,j,k,id;
    float n,factor;
    for(i=1;i<=n;i++){
        id = i;
        for(j=i+1;j<n;j++){
            if(fabs(arr[j][i]) > fabs(arr[id][i])){
                id = j;
            }
        }
        if(id != i){
            for(j=i;j<=n;j++){
                swap(arr[i][j], arr[id][j]);
            }
        }
        for(j=1;j<=n;j++){
            if(j!=1){
                factor = arr[j][i] / arr[i][i];
                for(k=i;k<=n;k++){
                    arr[j][k] -= factor * arr[i][k];
                }
            }
        }

    }
}
int main(){

    cout << fixed;
    cout << setprecision(1);
    int i,j,r,c,swapPossible = 0,foundOne;
    float divide,multi,temp, sum;


    initWithDefault();
gaussEliminationMethod();
gaussEliminationMethod2();
display();






    return 0;
}
