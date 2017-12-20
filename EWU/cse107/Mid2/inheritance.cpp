#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Person{
public:
    void walk(){
        cout << "This is the walk function." << endl;
    }
};
class Student:public Person{
public:
    void read(){
        cout << "This is the read function." << endl;
    }
};

class Employee: public Person{
public:
    void work(){
        cout << "This is the work function." << endl;
    }
};

int main(){
    Student s1;
    Employee e1;
    s1.read();
    s1.walk();
    e1.work();
    e1.walk();


	return 0;
}
