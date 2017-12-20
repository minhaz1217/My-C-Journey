#include<iostream>
using namespace std;
int main(){
    int numA, numB,numC,numD;
    char choice, extra, ope;
    for(;;){
        cout << "Enter Numbers: (A/B operator C/D): ";
        cin >> numA >> extra >> numB >> ope >>  numC >> extra >> numD;

        switch(ope){
            case '+':
            cout << "Ans: " << (numA*numD + numB*numC) / (numB * numD)    << endl;
            break;
            case '-':
            cout << "Ans: " << ((numA*numD - numB*numC) / (numB * numD)) << endl;
            break;
            case '*':
            cout << "Ans: " << (numA*numC) / (numB * numD) << endl;
            break;
            case '/':
            cout << "Ans: " << (numA*numD) / (numB * numC) << endl;
            break;
            default:
                cout << "Something went wrong, Please try again." << endl;
        }
        cout <<"Do another (y/n)?";
        cin >> choice;
        if(choice == 'n'){
            break;
        }else{
            continue;
        }
    }


    return 0;
}
