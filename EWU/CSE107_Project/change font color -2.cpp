#include<iostream>
#include<windows.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int NUMBER = 10;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, NUMBER);
	return 0;
}
