#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char *str = "Hello world";
    int len = strlen(str);
    char *ptr;
    ptr = new char[len+1];
    strcpy(ptr,str);
    cout << "Ptr: " << ptr << endl;
    delete [] ptr;
	return 0;
}
