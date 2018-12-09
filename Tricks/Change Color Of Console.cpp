#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
    //SetConsoleTextAttribute(consoleHandler, 0 | 1 | BACKGROUND_RED);
}


int main(){

    for(int i=0;i<=255;i++){
        changeConsoleColor(i);
        cout << "HELLO \t" << i  << endl;
    }
    return 0;
}
