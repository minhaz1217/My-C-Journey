#include<iostream>
using namespace std;
int main(){
    int i,j, spNum, pNum;
    double sales[4][5], price,total=0;
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            sales[i][j] = 0;
        }
    }

    for(;;){
        cout << "Enter your Sales Person Number: ";
        cin >> spNum;
        if(spNum == 0 || spNum >4){
            break;
        }
        cout << "Enter the product number: ";
        cin >> pNum;
        if(pNum == 0 || spNum > 5){
            break;
        }
        cout << "Enter total dollar value of that product sold that day: ";
        cin >> price;
        sales[spNum -1][pNum - 1] +=price;
    }

        for(i=0;i<4;i++){
            cout << "SalesPerson "<< i+1 << ": ";
            for(j=0;j<5;j++){
                cout << "Item"<< j+1 << " sold: " << sales[i][j] << " ";
                total += sales[i][j];
            }
            cout << "    Total: " <<total;
            total =0;
        cout << endl;
        }
        total =0;
        for(i=0;i<5;i++){
            for(j=0;j<4;j++){
                total+= sales[j][i];
            }
            cout << "     " << total;
            total = 0;
        }



    return 0;
}
