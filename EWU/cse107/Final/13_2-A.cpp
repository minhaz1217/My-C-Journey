#include<iostream>
using namespace std;
class AClass{
    int a;
public:
    AClass(int aa=0){
        a = aa;
    }
    void display(){
        cout << a << endl;
    }
};
