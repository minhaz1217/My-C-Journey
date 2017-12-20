#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    WORD color = 240;


    //color = csbiInfo.wAttributes;
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);


    /*
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs;
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    //First save the current color information

  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes;


   //Set the new color information

  SetConsoleTextAttribute ( h, FOREGROUND_RED& FOREGROUND_BLUE | BACKGROUND_BLUE  | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );

  printf ( "This is a test\n" );


   // Restore the original colors

  SetConsoleTextAttribute ( h, wOldColorAttrs);
  */
    return 0;
}
