#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<stack>
#include<windows.h>
#include<conio.h>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b<< endl;

#define MAX 1000
int variables,y,x,ty,tx, lastOpenVariable = 0;
int noSolutionPossible = 0;
//if 0 then solution possible,1 means no solution possible
float matrix[MAX][MAX];
float solutionset[MAX];
float inverse[MAX][MAX];
stack<int> openVariable;
char marker = 'p';
int colorDefault = 240;
char* projectTitle= "Solutions of System of linear equations using programming technique.";
void resetSolutionSet(){
    for(int i=0;i<MAX;i++){
        solutionset[i] = 0;
    }
}
void resetMatrices(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            matrix[i][j] = 0;
            inverse[i][j] = 0;
        }
    }
}
void pauseScreen(){
    char tempgetch = getch();
}
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}
void colorTemplateDefault(){
    changeConsoleColor(colorDefault);
}
void colorTemplate1(){
    changeConsoleColor(160);
}
void colorTemplate2(){
    changeConsoleColor(223);
}
void colorTemplate3(){
    changeConsoleColor(46);
}
void colorTemplateError(){
    changeConsoleColor(252);
}
void clearScreen(){
    system("cls");
    SetConsoleTitle(projectTitle);
    changeConsoleColor(27);
    cout <<setw(79) << "" << endl;
    cout << "     "<< projectTitle << "      " << endl;
    cout <<setw(79) << "" << endl;
    cout << endl;
    changeConsoleColor(colorDefault);
}
void display(){
    // this displays the matrix as is.
    int i,j;
    for(i=1;i<=y;i++){
        for(j=1;j<=x;j++){
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void displayInverse(){
    int i,j;
    for(i=1;i<=variables;i++){
        for(j=1;j<=variables;j++){
            cout << " " << matrix[i][j] << " ";
        }
        cout << " \t| ";
        for(j=1;j<=variables;j++){
            cout << " " << inverse[i][j] << " ";
        }
        cout << endl;
    }
}

void displayEquation(){
// this displays the matrix int equation format
    int i,j,temp;
    cout << "System of Equation:" << endl;
    for(i=1;i<=y;i++){
        cout << " ";
        for(j=1;j<x;j++){
            temp = matrix[i][j];
            if(temp == 0){
                cout << "     ";
            }else if(temp ==-1){
                if(j>1){
                    cout << " - " << marker << j;
                }else{
                    cout << marker << j;
                }
            }else if(temp < 0){
                if(j>1){
                    cout << " - " << matrix[i][j]*-1 << marker << j;
                }else{
                    cout << matrix[i][j] << marker << j;
                }
            }else if(temp == 1){//-1
                if(j>1){
                    cout << " + " << marker << j;
                }else{
                    cout << marker << j;
                }
            }else{
                if(j>1){
                    cout << " + " << matrix[i][j] << marker << j;
                }else{
                    cout << matrix[i][j] << marker << j;
                }
            }
            // the *-1 is so that the number shows positive and the minus is from OUR given minus
            // otherwise it shows 2 minuses
        }
        if(matrix[i][j] < 0){
            cout << " - " << matrix[i][j] *-1;
        }else{
            cout << " + " << matrix[i][j];
        }
        cout << " = 0 " << endl;
    }
}
void displaySolution(){
    int i;
    cout << "Solution Set: " << endl;
    for(i=1;i<x;i++){
        cout <<" " <<  marker << i << " = " << solutionset[i] << endl;
    }
}
int isTheRowAllZero(int row){
    // returns 0 if the row is not all zero, else returns 1
    int i;
    for(i=1;i<x;i++){
        if(matrix[i] != 0){
            return 0;
        }
    }
    return 1;
}
void rowswap(int row1, int row2){
    // this swaps row1 with row2
    int j;
    colorTemplate3();
    printf("Swaping R%d with R%d\n", row1, row2);
    colorTemplateDefault();
    for(j=1;j<=x;j++){
        swap(matrix[row1][j], matrix[row2][j]);
    }
    display();
}
void rowSwapForInverse(int row1, int row2){
    int j;
    colorTemplate3();
    printf("Swaping R%d with R%d\n", row1, row2);
    colorTemplateDefault();
    for(j=1;j<x;j++){
        swap(matrix[row1][j], matrix[row2][j]);
        swap(inverse[row1][j], inverse[row2][j]);
    }
    //swap(arr[row1][x], arr[row2][x]);
    displayInverse();
}
int checkForInvalidEquation(){
    int i,j,flag=0;
    //flag 0 means
    for(i=1;i<=y;i++){
        flag = 0;
        for(j=1;j<x;j++){
            if(matrix[i][j] != 0){
                // found a non zero value
                flag = 1;
                return 0; // 0 means invalid equation not found
            }
        }
        if(flag == 0){
            if(matrix[i][x] != 0){
                //it means all value of that row except the b is zero
                noSolutionPossible = 1;
                return 1;
            }
        }
    }
}
void checkForZeroRow(){
    //this checks for any all zero rows and swaps them to the bottom of the matrix and mark the column position as openvariable
    int i,j,flag = 1;
    // if flag == 1 then there is a zero row
    for(i=ty;i>=1;i--){
        flag = 1;
        for(j=1;j<tx;j++){
            if(matrix[i][j] != 0){
                //cout << arr[i][j] << endl;
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            //printf("All zero row exists.");
            /*
            if(lastOpenVariable != i){
                openVariable.push(i);
                lastOpenVariable = i;
            }
            */
            rowswap(i, ty);
            ty--;
            // ty decreases by 1 because we don't need any loop that goes to the last row
        }
    }
}
int checkForZeroRowInverse(){
    int i,j,flag = 1;
    //
    for(i=1;i<=ty;i++){
        flag =1;
        for(j=1;j<tx;j++){
            if(matrix[i][j] != 0){
                flag =0;
                break;
            }
        }
        if(flag == 0){
            // flag =0 means there are at least 1 non zero value
            return 1;
        }
    }
    //so we didn't find any non zero value, so zero row exists
    return 0;
}
void takeInput(){
    // this takes input
    int i,j;
    cout << "How many variables?: ";
    cin >> variables;
    noSolutionPossible = 0;
    resetSolutionSet();
    resetMatrices();

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
            cin>> matrix[i][j];
        }
    }
    cout << endl;
    displayEquation();
}
void takeInputForInverse(){
    int i,j;
    cout << "How many variables?: ";
    cin >> variables;
    y = variables;
    x = variables;
    ty = y;
    tx = x;
    /*
    for(i=1;i<=x;i++){
        solutionset[i] = 0;
    }
    */
    //cout << "Sample: ax1 + bx2 .....+ ijxN = 0" << endl;
    for(i=1;i<=ty;i++){
        for(j =1;j<=tx;j++){
            printf("Enter for R%dC%d: ", i,j);
            cin>> matrix[i][j];
        }
    }
    cout << endl;

}
void populateOpenVariablesAndFindSolution(){
    int r,foundOne,c,i,j;
    float sum;
    float num;
    int openVarCheck[MAX];
    for(i=1;i<MAX;i++){
        openVarCheck[i] = 1;
        // all x is open
    }
    for(i=1;i<= ty;i++){
        for(j=1;j<x;j++){
            if(matrix[i][j] == 1){
                openVarCheck[j] = 0;
                // from left to right if we find a column that has value 1 so, we know that x has a solution so it is not open
            }
        }
    }
    for(i=1;i<x;i++){
        if(openVarCheck[i] != 0){
            openVariable.push(i);
        }
    }

    if(openVariable.size() != 0){
        cout << "There are " << openVariable.size() << " open variables. Please insert input for them: \n";
        while(openVariable.size() != 0){
            cout << "Input for " << marker << openVariable.top() << ": ";
            cin >> num;
            solutionset[openVariable.top()] = num;
            openVariable.pop();
        }
    }
    for(r=y;r>=1;r--){
        foundOne = 0;
        sum = 0;
        for(c = 1;c<x;c++){
            if(matrix[r][c]==1){
                foundOne = 1;
                for(i=c+1;i<=x;i++){
                    if(i==x){
                        sum -= matrix[r][i];
                    }else{
                        sum = sum - matrix[r][i]*solutionset[i];
                    }
                }
                solutionset[c] = sum;
                if(r==1){
                    break;
                }
            }
        }
    }
}
void solutionofInverseMatrix(){
    int i,j;
    // taking the b to another matrix
    resetSolutionSet();
    for(i=1;i<=y;i++){
        for(j=1;j<x;j++){
            solutionset[i] += inverse[i][j] * (matrix[j][x]*-1);
        }
    }
}

void gaussEliminationMethod(){
    int r,c,swapPossible,i,j,foundOne;
    float divide,multi,temp,sum;
    resetSolutionSet();
    cout << "Starting Matrix: " << endl;
    display();
    for(r = 1,c=1;r<=ty;r++,c++){
        checkForZeroRow();
        if(checkForInvalidEquation()){
            noSolutionPossible = 1;
            break;
        }
        swapPossible = 0;
        if(matrix[r][c] == 0){
            for(i=r;i<=ty;i++){
                if(matrix[i][c] != 0){
                    swapPossible = 1;
                    rowswap(r, i);
                    break;
                }
            }
            // if no swap is possible then we just skip that row and that column
            if(swapPossible != 1){
                /*
                if(lastOpenVariable != c){
                    openVariable.push(c);
                    lastOpenVariable = c;
                }
                */
                r--;
                continue;
            }
        }
        divide = matrix[r][c];
        if(divide != 1){
            colorTemplate1();
            printf("Divide row %d by %.1lf\n", r, divide);
            colorTemplateDefault();
            //making row's first element 1
            for(i=c;i<=tx;i++){
                matrix[r][i] = matrix[r][i] / divide;
            }
            display();
        }
        if(divide == 0){
            display();
            /*
            if(lastOpenVariable != c){
                openVariable.push(c);
                lastOpenVariable = c;
            }
            */
            continue;
        }
        for(i=r+1;i<=ty;i++){
            multi = matrix[i][c];
            //printf("Row%d = Row%d - (%.1lf) * Row%d\n", i, i, arr[i][c], r);
            colorTemplate2();
            cout << "Row" << i << " = Row" << i << " - (" << matrix[i][c] << ") * Row"<< r<< endl;
            colorTemplateDefault();
            for(j=c;j<=tx;j++){
                temp =  matrix[i][j] - (multi * matrix[r][j]);
                matrix[i][j] = temp;
            }

        }
        display();
    }
    // solution
    //if foundOne ==0 then we know that is all zero row

    cout << "Final Matrix of Gaussian Elimination method: " << endl;
    display();
}
void gaussJordanMethod(){
    int r,c,swapPossible,i,j,foundOne;
    float divide,multi,temp,sum;
    resetSolutionSet();
    cout << "Starting Matrix: " << endl;
    display();
    for(r = 1,c=1;r<=ty;r++,c++){
        checkForZeroRow();
        if(checkForInvalidEquation()){
            noSolutionPossible = 1;
            break;
        }
        swapPossible = 0;
        if(matrix[r][c] == 0){
            for(i=r;i<=ty;i++){
                if(matrix[i][c] != 0){
                    swapPossible = 1;
                    rowswap(r, i);
                    break;
                }
            }
            // if no swap is possible then we just skip that row and that column

            if(swapPossible != 1){
                /*
                if(lastOpenVariable != c){
                    openVariable.push(c);
                    lastOpenVariable = c;
                }
                */
                r--;
                continue;
            }

        }
        divide = matrix[r][c];
        if(divide != 1){
            colorTemplate1();
            printf("Divide row %d by %.1lf\n", r, divide);
            colorTemplateDefault();
            //making row's first element 1
            for(i=c;i<=tx;i++){
                matrix[r][i] = matrix[r][i] / divide;
            }
            display();
        }
        if(divide == 0){
            display();
            /*
            if(lastOpenVariable != c){
                openVariable.push(c);
                lastOpenVariable = c;
            }
            */
            continue;
        }
        for(i=r+1;i<=ty;i++){
            multi = matrix[i][c];
            //printf("Row%d = Row%d - (%.1lf) * Row%d\n", i, i, arr[i][c], r);
            colorTemplate2();
            cout << "Row" << i << " = Row" << i << " - (" << matrix[i][c] << ") * Row"<< r<< endl;
            colorTemplateDefault();
            for(j=c;j<=tx;j++){
                temp =  matrix[i][j] - (multi * matrix[r][j]);
                matrix[i][j] = temp;
            }
        }
        display();
    }
    for(r=ty;r>1;r--){// r >1 because we don't have to apply anything for row 1
        checkForZeroRow();
        for(c=1;c<x;c++){
            // going left to right to find first element which has co-eff of 1
            if(matrix[r][c] == 1){
                for(i=r-1;i>=1;i--){//traversing up
                    multi = matrix[i][c];
                    colorTemplate2();
                    cout << "Row" << i << " = Row" << i << " - (" << matrix[i][c] << ") * Row"<< r<< endl;
                    colorTemplateDefault();
                    for(j=1;j<=x;j++){
                        temp =  matrix[i][j] - (multi * matrix[r][j]);
                        matrix[i][j] = temp;
                    }

                }
            }
        }
        display();
    }
    cout << endl << endl;
    cout << "Final Matrix of Gauss-Jordan Method." << endl;
    display();

    // solution
    //if foundOne ==0 then we know that is all zero row
}
void matrixInverse(){
    int r,c,swapPossible,i,j,foundOne, inverseNotPossible = 0;
    float divide,multi,temp,sum;
    for(i=1;i<=variables;i++){
        for(j=1;j<=variables;j++){
            if(i==j){
                inverse[i][j] = 1;
            }else{
                inverse[i][j] = 0;
            }
        }
    }

    resetSolutionSet();
    cout << "Starting Matrix: " << endl;
    displayInverse();
    for(r = 1,c=1;r<=ty;r++,c++){
        inverseNotPossible = !checkForZeroRowInverse();
        if(inverseNotPossible == 1){
            colorTemplateError();
            cout << "Inverse Not Possible. Zero Row Exists."<< endl;
            colorTemplateDefault();
            noSolutionPossible = 1;
            displayInverse();
            break;
        }
        swapPossible = 0;
        if(matrix[r][c] == 0){
            for(i=r;i<=ty;i++){
                if(matrix[i][c] != 0){
                    swapPossible = 1;
                    rowSwapForInverse(r, i);
                    break;
                }
            }
            // if no swap is possible then it can't form inverse
            if(swapPossible != 1){
                colorTemplateError();
                cout << "Inverse Not Possible. Swapping Not Possible." << endl;
                colorTemplateDefault();
                noSolutionPossible = 1;
                displayInverse();
                break;
            }
        }
        divide = matrix[r][c];
        if(divide != 1){
            colorTemplate1();
            printf("Divide row %d by %.1lf\n", r, divide);
            colorTemplateDefault();
            //making row's first element 1
            for(i=1;i<tx;i++){
                matrix[r][i] = matrix[r][i] / divide;
                inverse[r][i] = inverse[r][i] / divide;
            }
            displayInverse();
        }
        if(divide == 0){
            colorTemplateError();
            cout << "Inverse Not Possible. Divide By Zero." << endl;
            colorTemplateDefault();

            noSolutionPossible = 1;
            displayInverse();
            break;
        }
        for(i=r+1;i<=ty;i++){
            multi = matrix[i][c];
            //printf("Row%d = Row%d - (%.1lf) * Row%d\n", i, i, arr[i][c], r);
            colorTemplate2();
            cout << "Row" << i << " = Row" << i << " - (" << matrix[i][c] << ") * Row"<< r<< endl;
            colorTemplateDefault();
            for(j=1;j<tx;j++){
                matrix[i][j] = matrix[i][j] - (multi * matrix[r][j]);
                inverse[i][j] = inverse[i][j] - (multi * inverse[r][j]);
            }
        }
        displayInverse();
    }
    for(r=ty;r>1;r--){// r >1 because we don't have to apply anything for row 1
        checkForZeroRow();
        for(c=1;c<x;c++){
            // going left to right to find first element which has co-eff of 1
            if(matrix[r][c] == 1){
                for(i=r-1;i>=1;i--){//traversing up
                    multi = matrix[i][c];
                    colorTemplate2();
                    cout << "Row" << i << " = Row" << i << " - (" << matrix[i][c] << ") * Row"<< r<< endl;
                    colorTemplateDefault();
                    for(j=1;j< x;j++){
                        matrix[i][j] = matrix[i][j] - (multi * matrix[r][j]);;
                        inverse[i][j] = inverse[i][j] - (multi * inverse[r][j]);;
                    }
                }
            }
        }
        displayInverse();
    }
}
void menu(){
    int ch;
    while(1){
    clearScreen();
    cout << "\n1. Input Equation." << endl;
    cout << "2. Show Equation." << endl;
    cout << "3. Solve Using Gauss Elimination." << endl;
    cout << "4. Solve Using Gauss Jordan Elimination." << endl;
    cout << "5. Solve Using Matrix Inverse." << endl;
    cout << "6. Find Matrix Inverse." << endl;
    cout << "0. Exit"<< endl;
    cin >> ch;
        if(ch == 1){
            takeInput();
        }else if(ch == 2){
            displayEquation();
        }else if(ch == 3){
            gaussEliminationMethod();
            if(noSolutionPossible == 1){//solution no possible
                colorTemplateError();
                cout << "Solution not possible because invalid row exists." << endl;
                colorTemplateDefault();
            }else{
                populateOpenVariablesAndFindSolution();
                displaySolution();
            }
        }else if(ch == 4){
            gaussJordanMethod();
            if(noSolutionPossible == 1){//solution no possible
                colorTemplateError();
                cout << "Solution not possible because invalid row exists." << endl;
                colorTemplateDefault();
            }else{
                populateOpenVariablesAndFindSolution();
                displaySolution();
            }
        }else if(ch == 5){
            matrixInverse();
            if(noSolutionPossible == 1){//solution no possible
                colorTemplateError();
                cout << "Solution not possible because invalid row exists." << endl;
                colorTemplateDefault();
            }else{
                solutionofInverseMatrix();
                displaySolution();
            }
        }else if(ch == 6){
            matrixInverse();
            if(noSolutionPossible == 1){//solution no possible
                colorTemplateError();
                cout << "Solution not possible because invalid row exists." << endl;
                colorTemplateDefault();
            }else{
                cout << "Inverse Of The Matrix: " << endl;
                for(int i =1;i<=y;i++){
                    for(int j=1;j<x;j++){
                        cout << " " << inverse[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }else if(ch == 0){
            colorTemplate2();
            cout << "\n";
            cout << "THANKS YOU VERY MUCH." << endl;
            cout << endl;
            colorTemplateDefault();
            Sleep(1000);
            exit(0);
        }else{
            menu();
        }
        cout << "Press Any Key To Continue...";
        pauseScreen();
    }
}
int main(){
    system("color f0");
    //changing color of the whole console. to white back and black text
    cout << fixed;
    cout << setprecision(2);
    menu();

    return 0;
}
