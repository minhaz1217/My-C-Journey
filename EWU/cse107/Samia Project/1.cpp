#include<iostream>
#include<fstream>
using namespace std;
int total_employee_salary = 0;
// 4
// car_cost
// house rent , telephone bill
// salary input and then devide then and send it to another class's function
class value
{
public:
    int house_rent, telephone_bill, car_cost, servant_cost;
    value()
    {
        house_rent=6000;
        telephone_bill=1000;
        car_cost=7000;
        servant_cost=3000;
    }
    //Input value:
    virtual int getPerks() {}
};
class input
{
public:
    int get_value(char fileName[], string employeeType,int addedPerks)
    {
        int i,number,total = 0;
        ofstream outfile;
        outfile.open(fileName, ios::app);
        /*
        cout << "How many employee's salary do you want to enter?: ";
        cin >> number;
        int a[number];
        for(i=0; i<number; i++){
            cout <<"Enter employee salary("<< i+1 << "): ";
            cin>>a[i];
            outfile << "Salary of " << employeeType << " number " << i+1 << " is: " << a[i]+addedPerks << endl;
            total += a[i]+addedPerks;
            */
        outfile << employeeType << " " << addedPerks << endl;
        total += addedPerks;
        //}
        outfile.close();
        return total;
    }
};

class Senior_employee_salary:public input, public value
{
    int total_senior_salary;
public:
    Senior_employee_salary()
    {
        total_senior_salary = 0;
    }
    int senior_employee(int salary)
    {
        char file_name[] = "Salary_Of_Senior_Employee.txt";
        int total1=input::get_value(file_name, "Senior Employee",salary + get_perks());
        total_senior_salary += total1;
        total_employee_salary += total1;
        //int  house_rent,telephone_bill,car_cost,servant_cost;
    }
    int get_perks()
    {
        value a3;
        return (a3.house_rent + a3.car_cost + a3.servant_cost + a3.telephone_bill);
    }
    int get_senior_salary()
    {
        return total_senior_salary;
    }
};
class junior_employee_salary :public input, public value
{
    int total_junior_salary;
public:
    junior_employee_salary()
    {
        total_junior_salary = 0;
    }
    int junior_employe(int salary)
    {
        char file_name[] = "Salary_Of_Junior_Employee.txt";
        int total2=input::get_value(file_name, "Junior Employee",salary + get_perks());
        total_junior_salary +=total2;
        total_employee_salary += total2;
    }
    int get_perks()
    {
        value a2;
        return (a2.house_rent + a2.servant_cost + a2.telephone_bill);
    }
    int get_junior_salary()
    {
        return total_junior_salary;
    }
};
class Servent_salary:public input
{
    int total_servent_salary;
public:
    Servent_salary()
    {
        total_servent_salary = 0;
    }
    int Servent(int salary)
    {
        char file_name[] ="Servent_Salary.txt";
        int total3=input::get_value(file_name ,"Servent", salary + get_perks());
        total_servent_salary += total3;
        total_employee_salary += total3;
    }
    int get_perks()
    {
        value a1;
        return (a1.car_cost + a1.servant_cost);
    }
    int get_servent_salary()
    {
        return total_servent_salary;
    }
};
class total_salary_of_employees:public value
{
public:
    int total_salary()
    {
        int total=total_employee_salary;
        ofstream outfile;
        outfile.open("Total_Salary.txt");
        cout<<"Total salary: "<<total<<endl;
        outfile<<"Total salary: "<<total<<endl;
        outfile.close();
    }
};
int main()
{
    /*
    value A;
    A.value1();
    input B;
    B.get_value();
    */
    /*
    Senior_employee_salary C;
    C.senior_employee();
    junior_employee_salary D;
    D.junior_employe();
    Servent_salary E;
    E.Servent();
    total_salary_of_employees F;
    F.total_salary();
    */
    Senior_employee_salary s_obj;
    junior_employee_salary j_obj;
    Servent_salary sv_obj;

    int salary[11];
    ifstream infile("salaries.txt");
    for(int i=0; i<11; i++)
    {
        infile >> salary[i];
    }
    infile.close();
    for(int i=0; i<10; i++)
    {
        if(salary[i] >= 100000)
        {
            s_obj.senior_employee(salary[i]);
        }
        else if(salary[i] >=50000 && salary[i] <100000)
        {
            j_obj.junior_employe(salary[i]);
        }
        else
        {
            sv_obj.Servent(salary[i]);
        }
    }


    ofstream outfile;
    outfile.open("Salary_Of_Senior_Employee.txt", ios::app);
    cout<<"Salary Of Senior Employees: "<< s_obj.get_senior_salary()<<endl;
    outfile<<"Salary Of Senior Employees: "<< s_obj.get_senior_salary()<<endl;
    outfile.close();

    outfile.open("Salary_Of_Junior_Employee.txt", ios::app);
    cout<<"Salary Of junior Employees: "<<j_obj.get_junior_salary()<<endl;
    outfile<<"Salary Of junior Employees: "<<j_obj.get_junior_salary()<<endl;
    outfile.close();

    outfile.open("Servent_Salary.txt", ios::app);
    cout<<"Servent_salary: "<<sv_obj.get_servent_salary()<<endl;
    outfile<<"Servent salary: "<<sv_obj.get_servent_salary()<<endl;
    outfile.close();
    total_salary_of_employees F;
    F.total_salary();
}
