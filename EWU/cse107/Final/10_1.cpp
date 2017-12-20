#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int *intp;
    float fnum;
    intp = reinterpret_cast<int*>(fnum);
    check(*intp);
	return 0;
}
