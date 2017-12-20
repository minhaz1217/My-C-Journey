#include<iostream>
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
    Child1(int a):Parent1(a){
        numc1 = a;
    }
    void display1(){
        cout << numc1 << endl;
    }
};
class Child2:public Parent1{
    int numc2;
public:
    Child2(int a):Parent1(a){
        numc2 = a;
    }
    void display2(){
        cout << numc2 << endl;
    }
    void display1(){}
};


int main(){
    Parent1 *p1;
    p1 = new Child1(5);
    p1->display1();
    Child1 c1(10);
    Child1 *cp1;
    Child2 c2(20);
    c1.display1();
    c2.display2();

    if(cp1 = dynamic_cast<Child1*>(p1)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

	return 0;
}
