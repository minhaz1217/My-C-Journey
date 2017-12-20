#include<stdio.h>
main(){
    int a,b,c,d,e;
    a = 7; //00000000000111
    b = 5; //00000000000101

    c = a&b;
    d = a|b;
    e = a^b;
    printf("And %d\n", c);
    printf("Or %d\n", d);
    printf("Exclusive Or: %d\n", e);
    printf("%d\n", ~a);


}
