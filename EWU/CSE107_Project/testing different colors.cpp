#include<iostream>
#include<windows.h>
using namespace std;
#define check(a) cout<<a<< endl;
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}

int main(){
    for(int i=0;i<=255;i++){
        changeConsoleColor(i);
        cout << "This is: " << i << endl;
    }
    int a;
    cin >> a;
	return 0;
}
