#include<stdio.h>
main(){
    int a,i;
    a = 2;
    i=1;
    a = a+ i++;
    printf("%d\n", a);
    printf("%d\n", i);
}
