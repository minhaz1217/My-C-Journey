#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Class{
private:
    int counter ;
public:
    Class(int c){
        counter = c;
    }
    friend ostream& operator << (ostream& os, const Class &c1);
};
ostream& operator << (ostream& os, const Class &c1){
    os << c1.counter << endl;
    return os;
}

int main(){
    Class obj1(5);
    cout << obj1 << endl;



	return 0;
}
