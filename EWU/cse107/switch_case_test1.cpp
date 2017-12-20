#include<iostream>
using namespace std;
struct Bird{
    int a, b;
};
struct CanFly{
    int a,b;
    Bird c;
};
int main(){
    CanFly cf;
    cf = {1,2,{3,4}};
    cout << cf.c.a;
	return 0;
}
