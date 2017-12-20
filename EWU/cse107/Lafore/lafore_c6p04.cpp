#include<iostream>
using namespace std;
class Employee{
private:
    int employee;
    float salary;
public:
    Employee(int a=0,float b=0):employee(a) , salary(b){}
    void setEmployee(int a){
        employee = a;
    }
    void setSalary(float a){
        salary =a;
    }
    void setData(int a, float b){
        employee = a;
        salary = b;
    }
    void display(){
        cout << "Employee: " << employee << endl;
        cout << "Salary: " << salary << endl;
    }
};
int main(){
    int a;
    float b;
    Employee e[3];
    for(int i=0;i<3;i++){
    cout << "Enter employee number: ";
    cin >> a;
    cout << "Enter Employee Salary: ";
    cin >> b;
    e[i].setData(a,b);
    }
    for(int i=0;i<3;i++){
        e[i].display();
    }
	return 0;
}
