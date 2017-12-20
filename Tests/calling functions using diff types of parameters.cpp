#include<iostream>
using namespace std;
void thisIsCallingByValue(int a){
    a++;
}
void thisIsCallingByRef(int &a){
    a++;
}
void thisIsCallingByPointer(int *a){
    (*a)++;
}
int main(){
    int test1 = 10, test2 = 20,test3 = 30;
    cout << "Before calling by referance: " << test1 << endl;
    thisIsCallingByValue(test1);
    cout << "After calling by refarance: " << test1 << endl;

    cout << "Before calling by referance: " << test2 << endl;
    thisIsCallingByRef(test2);
    cout << "After calling by refarance: " << test2 << endl;

    cout << "Before calling by referance: " << test3 << endl;
    thisIsCallingByPointer(&test3);
    cout << "After calling by refarance: " << test3 << endl;
	return 0;
}
