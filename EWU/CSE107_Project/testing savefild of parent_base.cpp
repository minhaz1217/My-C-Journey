#include<iostream>
#include<fstream>
using namespace std;
#define check(a) cout<<a<< endl;
class Parent1{
    int numP;
public:
    Parent1(int a){
        numP = a;
    }
    void display(){
        cout << numP << endl;
    }
    virtual void display1() = 0;
};
class Child1:public Parent1{
    int numc1;
public:
    Child1(int a=0):Parent1(a){
        numc1 = a;
    }
    void display1(){
        cout << numc1 << endl;
    }
    void writeThis(){
    ofstream outFile;
    outFile.open("testOut.DAT", ios::binary);
    outFile.write((char *)this, sizeof(*this));
    outFile.close();
    }
    void readThis(){
        ifstream infile;
        infile.open("testOut.DAT", ios::binary);
        infile.read((char*)this, sizeof(*this));
        infile.close();
    }
};



int main(){
    Parent1 *p1;
    p1= new Child1(20);

    ofstream outFile;
    outFile.open("testOut3.DAT", ios::binary);
    outFile.write((char *)p1, sizeof(p1));
    outFile.close();

    ifstream infile;
    infile.open("testOut3.DAT", ios::binary);
    infile.read((char*)p1, sizeof(p1));
    infile.close();
    p1->display1();


    //writing and reading a single file
    //writing the file, note the & sign
    /*
    Child1 c1(15);
    ofstream outFile;
    outFile.open("testOut2.DAT", ios::binary);
    outFile.write((char *)&c1, sizeof(&c1));
    outFile.close();
    */
    //Reading the file, note the * and &
    /*
    ifstream infile;
    infile.open("testOut2.DAT", ios::binary);
    infile.read((char*)&c1, sizeof(&c1));
    infile.close();
    c1.display1();
    */




    /*
    if(cp1 = dynamic_cast<Child1*>(p1)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    */
	return 0;
}
