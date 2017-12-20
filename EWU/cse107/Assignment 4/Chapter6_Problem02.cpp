#include<iostream>
#include<conio.h>
using namespace std;
class ToolBooth{
private:
    unsigned int totalCars;
    double totalAmount;
public:
    ToolBooth():totalCars(0), totalAmount(0){}
    void payingCar(){
        cout << "Paying car added." << endl;
        totalCars++;
        totalAmount += .50;
    }
    void nopayCar(){
        cout << "No pay car added." << endl;
        totalCars++;
    }
    void display(){
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Amount: " << totalAmount << endl;
    }
};
int main(){
    ToolBooth t1;
    int a;
    for(;;){
        a = getch();
        if(a == 48){
            t1.nopayCar();
        }else if(a==49){
            t1.payingCar();
        }else if(a==27){
            t1.display();
            break;
        }
    }


	return 0;
}
