#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class A{
private:
    int a;
public:
    A(int n1=0){
        a = n1;
    }
    void display(){
        cout << "A: " << a << endl;
    }
    void walk(){
        cout << "I'm the walk" << endl;
    }
};
class B: public A{
private:
    int b;
public:
    B(int n1){
        b = n1;
    }
    void display(){
        cout << "B: " << b << endl;
        A::display();
    }
};
int main(){
    B obj(2);
    obj.display();
    obj.walk();

	return 0;
}
