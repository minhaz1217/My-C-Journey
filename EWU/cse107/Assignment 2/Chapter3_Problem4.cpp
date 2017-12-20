#include<iostream>
using namespace std;
int main(){
    float num1, num2;
    char ope,choice;

    for(;;){
        cout << "Enter first number, operator, second number: ";
        cin >> num1 >> ope >> num2;
        switch(ope){
            case '+':
            cout << "Ans: " << num1 + num2 << endl;
            break;
            case '-':
            cout << "Ans: " << num1 - num2 << endl;
            break;
            case '*':
            cout << "Ans: " << num1 * num2 << endl;
            break;
            case '/':
            cout << "Ans: " << num1 / num2 << endl;
            break;
            default:
                cout << "Something went wrong, Please try again." << endl;
        }
        cout <<"Do another (y/n)?";
        cin >> choice;
        if(choice == 'n'){
            break;
        }
    }
    return 0;
}
