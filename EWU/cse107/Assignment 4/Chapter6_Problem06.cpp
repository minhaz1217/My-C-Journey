#include<iostream>
using namespace std;
enum etype{laborer, secretary, manager, accountant, executive, researcher};
class Date{
private:
    int day, month, year;
public:
    void getDate(){
        char extra;
        cout << "Enter date(dd/mm/yy): ";
        cin >> day >> extra >> month >> extra >> year;
    }
    void showDate(){
        cout << day << "/" << month << "/" << year << endl;
    }
};
class Employee{
private:
    int employee;
    float salary;
    Date startDate;
    etype type;

public:
    Employee(int a=0,float b=0):employee(a) , salary(b){}
    void putemployee(){
        char t;
        cout << "Enter Employee Number: ";
        cin >> employee;
        cout << "Enter Employee Salary :";
        cin >> salary;
        startDate.getDate();
        cout << "Enter Employee type (First letter only)(l, s, m, a, e,r ): ";
        cin >> t;
        switch(t){
        case 'l':
            type = laborer;
            break;
        case 's':
            type = secretary;
            break;
        case 'm':
            type = manager;
            break;
        case 'a':
            type = accountant;
            break;
        case 'e':
            type = executive;
            break;
        case 'r':
            type = researcher;
            break;
        }
    }
    void getemployee(){
        cout << "Employee Number: " << employee << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "Employee start date: ";
        startDate.showDate();
        cout << "Employee type: ";
        switch(type){
            case 0:
                cout << "Laborer";
                break;
            case 1:
                cout << "Secretary";
                break;
            case 2:
                cout << "Manager";
                break;
            case 3:
                cout << "Accountant";
                break;
            case 4:
                cout << "Executive";
                break;
            case 5:
                cout << "Researcher";
                break;
        }
        cout << endl;
    }
};

int main(){
    int a;
    float b;
    Employee e[3];

    for(int i=0;i<3;i++){
        e[i].putemployee();

    }
    for(int i=0;i<3;i++){
        e[i].getemployee();
        cout << endl;
    }

	return 0;
}
