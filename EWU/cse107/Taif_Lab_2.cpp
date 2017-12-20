#include<iostream>
using namespace std;
class car{
private:
    string carname, carcolor, carsolddate;
public:
    car(){
        carname = "xxxx";
        carcolor = "xxxx";
        carsolddate="xxxx";
    }
    car(string cn, string cc,string sd){
        carname = cn;
        carcolor =cc;
        carsolddate = sd;
    }
    void show_info(){
        cout << "Carname: " << carname << endl;
        cout << "Car color: " << carcolor << endl;
        cout << "Car Sold Date: " << carsolddate << endl;
    }
    ~car(){
        cout << "destructor called"  << endl;
    }
};


int main(){
    car c1,c2("Toyota", "White", "25-2-2015"),c3("Lamborgini", "Black", "12-3-1010");
    c1.show_info();
    c2.show_info();
    c3.show_info();

	return 0;
}
