#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
class Person{
public:
    string str;
    Person(){
        str = "HI";
    }
    Person(string s){
        str = s;
    }
    void display1(){
        cout << str << endl;
    }
};
class Male: public Person{
public:
    int a;
    Male(){
        a = 40;
    }
    void display(){
        cout << a << endl;
    }
    void display1(){
        cout << a << endl;
    }
};


int main(){
    Person *p;
    p = new Male();
    Male *m = static_cast<Male *>(p);
    m->display();


	return 0;
}
