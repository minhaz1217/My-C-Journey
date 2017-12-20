#include<stdio.h>
main(){
    int a,res;
    float b ;
    double c;
    a = 10;
    b = 1234567890.252345234523452345;
    c = 1234567890.12345678901234567890123456789;
    printf("%e\n", b);
    printf("%2.5lf", c);
}
