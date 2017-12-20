#include<iostream>
using namespace std;
template <class T>
T add(T a, T b){
    return (a+b);
}
int main(){
    int aint = 5, bint = 10;
    float afloat = 34.33, bfloat = 54.444;
    cout << add(aint, bint) << endl;
    cout << add(afloat, bfloat) << endl;
	return 0;
}
