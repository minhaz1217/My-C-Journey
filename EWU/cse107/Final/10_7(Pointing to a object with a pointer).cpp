#include<iostream>
using namespace std;
class Counter{
    int c;
public:
    Counter(int ct=0){
        c = ct;
    }
    void display(){
        cout << c << endl;
    }
};
int main(){
    Counter c1(10);
    c1.display();
    Counter *pc;
    pc = &c1;
    pc->display();
	return 0;
}
