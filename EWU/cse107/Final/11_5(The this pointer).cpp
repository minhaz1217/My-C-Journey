#include<iostream>
using namespace std;
class People{
    int age;
public:
    People(int a=0){
        this->age = a;
    }
    void callDisplay(){
        this->display();
    }
    void display(){
        cout << this->age << endl;
    }
};
int main(){
    People p1(50);
    p1.callDisplay();
	return 0;
}
