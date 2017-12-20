#include<iostream>
using namespace std;
int main(){
    int i, num, j;
    for(i=0;i<5;i++){
        cout << "Enter a number: ";
        cin >> num;
        for(j=1;j<=num;j++){
            cout << "*" ;
        }
        cout << endl;
    }

    return 0;
}
