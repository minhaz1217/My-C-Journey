#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Class{
    int counter ;
public:
    Class(int c=0){
        counter = c;
    }
    void display(){
        cout << counter << endl;
    }
};
int main(){
    Class obj1(10);
    Class obj2;
    obj2 = obj1;
    obj2.display();
	return 0;
}
