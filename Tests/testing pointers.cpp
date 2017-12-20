#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Counter{
public:
    int a,b,c,d;
};
int main(){
    int *b,c;
    int **a,*d;
    Counter cc,*cp;
    c = 10;
    b = &c;
    a = &b;
    char *ccp;
    check(sizeof(a))
	return 0;
}
