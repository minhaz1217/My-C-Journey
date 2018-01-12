#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

bool isLeapYear(int year)
{
if (year % 400 == 0) return true;
else if(year % 100 == 0) return false;
else if(year % 4 == 0) return true;
else return false;
}


int main(){
    int a,b,y1,y2,tc,ans = 0,i,caseCounter=1;
    c(isLeapYear(1988));


    return 0;
}
