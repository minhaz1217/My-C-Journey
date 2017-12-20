#include<iostream>
#include <stdlib.h>
using namespace std;
int main(){
    char *p = "50000 500 30 -40";
    char *remain;
    remain = p;
    long i = strtol(p, &remain, 10);
    cout << i << endl;
    cout << remain << endl;
    p = remain;
    i = strtol(p,&remain, 10);
    cout << i << endl;
    cout << remain << endl;
}
