#include<iostream>
using namespace std;
class People{
    public:
    string name;
    virtual void display() = 0;
};
class Student: public People{
    int id;
public:
    Student(string n="", int i=0){
        name = n;
        id = i;
    }
    void display(){
        cout << name << endl;
        cout << id << endl;
    }
};
int main(){
    Student s("minhaz", 110);
    s.display();
	return 0;
}
