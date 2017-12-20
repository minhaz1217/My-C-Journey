#include<iostream>
using namespace std;
class employee{
private:
    string name;
    long employeeNumber;
public:
    void getData(){
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Employee Number: ";
        cin >> employeeNumber;
    }
    void putData(){
        cout << "Employee name: " << name << endl;
        cout << "Employee number: " << employeeNumber << endl;
    }
};
int main(){
    employee e[3];
    for(int i=0;i<3;i++){
        e[i].getData();
    }
    for(int i=0;i<3;i++){
        e[i].putData();
    }
	return 0;
}
