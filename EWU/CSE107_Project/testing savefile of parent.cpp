#include<iostream>
#include<fstream>
using namespace std;
#define check(a) cout<<a<< endl;
class Parent1{
public:
    int numP;

    Parent1(int a){
        numP = a;
    }
    void display(){
        cout << numP << endl;
    }

    virtual void display1() = 0;
    virtual void readThis() = 0;
    virtual void writeThis() = 0;
};
class Child1:public Parent1{
    int numc1;
    string name;
public:
    Child1(int a=0, int b=0,string n=""):Parent1(a){
        numc1 = b;
        name = n;
    }
    void display1(){
        cout << name << endl;
        cout << numc1 << endl;
        cout << numP << endl;
    }
    void writeThis(){
    ofstream outFile;
    outFile.open("testOut.DAT", ios::binary);
    //outFile.write((char *)this, sizeof(*this));
    outFile << name << endl;
    outFile << numc1 << endl;
    outFile << numP << endl;
    outFile.close();
    }
    void readThis(){
        ifstream infile;
        infile.open("testOut.DAT", ios::binary);
        infile >> name;
        infile >> numc1;
        infile >> numP;
        infile.close();
    }
};



int main(){
    Parent1 *p1;
    p1= new Child1(2330,100,"miadfadfadsfn");
    //Child1 c1(10,15,"f");
    //p1->writeThis();
    p1->readThis();
    p1->display1();

    /*
    cout << "Before file" << endl << endl;
    //p1->display1();
    cout << "After file" << endl << endl;
    ofstream outFile;
    outFile.open("testOut3.txt");
    outFile.write((char *)p1, sizeof(Child1));
    outFile.close();
    /*
    ifstream infile;
    infile.open("testOut3.DAT", ios::binary);
    infile.read((char*)p1, sizeof(Child1));
    infile.close();
   //p1->display1();
    */

    //writing and reading a single file
    //writing the file, note the & sign
    /*

    */



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
