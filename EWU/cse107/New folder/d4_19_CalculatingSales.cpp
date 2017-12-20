#include<iostream>
using namespace std;
main(){
    int pId , pCount;
    double totalPrice = 0, price;
    for(;;){
        cout << "Enter product id: ";
        cin >> pId;
        cout << "Enter Quantity: ";
        cin >> pCount;
        if(pId < 1 || pId > 5){
            break;
        }
        switch(pId){
        case 1:
            price = 2.98;
            break;
        case 2:
            price = 4.50;
            break;
        case 3:
            price = 9.98;
            break;
        case 4:
            price = 4.49;
            break;
        case 5:
            price = 6.87;
            break;
        default:
            price = 0;
        }
        totalPrice += price * pCount;
    }
    cout << "Total retail value of all products sold last week: " <<  totalPrice;
}
