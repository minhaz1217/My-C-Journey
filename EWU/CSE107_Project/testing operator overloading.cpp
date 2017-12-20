#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Count{
    int counter;
public:
    Count(){
        counter = 0;
    }
    void operator =(int s){
        counter = s;
    }
    void display(){
        cout << counter << endl;
    }
};
int main(){
    Count c;

    c = 10;
    c.display();
	return 0;
}
