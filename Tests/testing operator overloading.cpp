#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class len{
private:
    int a;
    int c;
public:
    len(int b=0,int d=0){
        a= b;
        c=d;
    }
    void show(){
        cout << a << endl;
        check(c);
    }
    len operator +(len l2){
        cout <<"Current is: "<<a<< endl;
        cout <<"Parameter is: "<<l2.a<<endl;
        return len(a + l2.a);
    }
};


int main(){
    len l1(5),l2(10),l3(0,10);
    l3 = l1+l2;
    l3.show();
	return 0;
}
