#include<iostream>
using namespace std;
int main(){
    // 12 pence = 1 shillings
    // 20 shillings == 1 pounds
    int pounds1, shillings1, pence1,pounds2, shillings2, pence2, totalPounds = 0, totalShillings = 0, totalPence = 0;
    char extra;
    cout << "Enter first amount: \x9c";
    cin >> pounds1 >> extra >> shillings1>> extra>> pence1;
    cout << "Enter Second amount: \x9c";
    cin >> pounds2 >> extra >> shillings2 >> extra >> pence2;
    totalPence += (pence1 + pence2);

    if(totalPence >= 12){
        totalShillings += (totalPence / 12) ;
        totalPence = (totalPence % 12) ;
    }
    totalShillings += (shillings1 + shillings2);

    if(totalShillings >= 20){
        totalPounds += (totalShillings / 20) ;
        totalShillings = (totalShillings%20);
    }
    totalPounds += (pounds1 + pounds2);
    cout << "Total is: \x9c" << totalPounds << "."<< totalShillings << "."<< totalPence;
    return 0;
}
