#include<iostream>
#include<fstream>
using namespace std;
class Student{
    string studentName;
    int id;
public:
    Student(string n="", int i = 0){
        studentName = n;
        id = i;
    }
    void writeThis(){
        ofstream out;
        out.open("input.dat", ios::binary);
        out.write((char*)this, sizeof(*this));
        out.close();
    }
    void readThis(){
        ifstream in;
        in.open("input.dat", ios::binary);
        in.read((char*)this, sizeof(*this));
    }
    void display(){
        cout << "Name: " << studentName << endl;
        cout << "ID: " << id << endl;
    }
};
int main(){
    Student s1("minhaz" , 110) , s2("haydar", 100);
    s1.writeThis();
    Student s3;
    s3.readThis();
    s3.display();
    s2.writeThis();
    Student s4;
    s4.readThis();
    s4.display();
	return 0;
}
